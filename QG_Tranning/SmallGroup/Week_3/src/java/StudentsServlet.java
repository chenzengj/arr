/**
 * @AUTHOR czj
 * package_name PACKAGE_NAME
 * @DATE 2024/4/4 20:49
 */
import com.google.gson.Gson;
import com.google.gson.JsonObject;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet("/students")
public class StudentsServlet extends HttpServlet {

    private static List<Student> students = new ArrayList<>();//学生表
    private static int nextId = 1;//默认第一个id为1

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        Gson gson = new Gson();
        //将结果封装为json响应
        String json = gson.toJson(students);
        resp.setCharacterEncoding("UTF-8"); // 设置响应编码为 UTF-8
        resp.setContentType("application/json");
        resp.getWriter().write(json);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        //获取请求中的json数据
        BufferedReader reader = req.getReader();
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            sb.append(line);
        }
        String jsonData = sb.toString();
//      用gson解析json数据
        Gson gson = new Gson();
        JsonObject jsonObject = gson.fromJson(jsonData, JsonObject.class);
        String name = jsonObject.get("name").getAsString();
        int age = jsonObject.get("age").getAsInt();

        Student student = new Student(nextId++, name, age);
        students.add(student);//将student对象加入表中

        JsonObject responseJson = new JsonObject();
        responseJson.addProperty("success", true);
        String json = gson.toJson(responseJson);
        resp.setCharacterEncoding("UTF-8"); // 设置响应编码为 UTF-8
        resp.setContentType("application/json");
        resp.getWriter().write(json);
    }

//    @Override
//    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws IOException {
//        String pathInfo = req.getPathInfo();
//        if (pathInfo != null) {
//            int id = Integer.parseInt(pathInfo.substring(1));
//            boolean success = deleteStudent(id);
//
//            JsonObject responseJson = new JsonObject();
//            responseJson.addProperty("success", success);
//            if (!success) {
//                responseJson.addProperty("message", "删除学生失败");
//            }
//            String json = new Gson().toJson(responseJson);
//            resp.setContentType("application/json");
//            resp.getWriter().write(json);
//        }
//    }

//    private boolean deleteStudent(int id) {
//        for (Student student : students) {
//            if (student.id == id) {
//                students.remove(student);
//                return true;
//            }
//        }
//        return false;
//    }

    private static class Student {
        int id;
        String name;
        int age;

        public Student(int id, String name, int age) {
            this.id = id;
            this.name = name;
            this.age = age;
        }
    }
}
/*@WebServlet("/students")
public class StudentsServlet extends HttpServlet {

    private static final String DB_URL = "jdbc:mysql://localhost:3306/db01";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "771015";

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        List<Student> students = getStudents();
        Gson gson = new Gson();
        String json = gson.toJson(students);
        resp.setContentType("application/json");
        resp.getWriter().write(json);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        BufferedReader reader = req.getReader();
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            sb.append(line);
        }
        String jsonData = sb.toString();

        Gson gson = new Gson();
        JsonObject jsonObject = gson.fromJson(jsonData, JsonObject.class);
        String name = jsonObject.get("name").getAsString();
        int age = jsonObject.get("age").getAsInt();

        boolean success = addStudent(name, age);

        JsonObject responseJson = new JsonObject();
        responseJson.addProperty("success", success);
        if (!success) {
            responseJson.addProperty("message", "添加学生失败");
        }
        String json = gson.toJson(responseJson);
        resp.setContentType("application/json");
        resp.getWriter().write(json);
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String pathInfo = req.getPathInfo();
        if (pathInfo != null) {
            int id = Integer.parseInt(pathInfo.substring(1));
            boolean success = deleteStudent(id);

            JsonObject responseJson = new JsonObject();
            responseJson.addProperty("success", success);
            if (!success) {
                responseJson.addProperty("message", "删除学生失败");
            }
            String json = new Gson().toJson(responseJson);
            resp.setContentType("application/json");
            resp.getWriter().write(json);
        }
    }

    private List<Student> getStudents() {
        List<Student> students = new ArrayList<>();
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "SELECT * FROM students";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                int age = rs.getInt("age");
                students.add(new Student(id, name, age));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return students;
    }

    private boolean addStudent(String name, int age) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "INSERT INTO students (name, age) VALUES (?, ?)";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, name);
            stmt.setInt(2, age);
            int rowsInserted = stmt.executeUpdate();
            return rowsInserted > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    private boolean deleteStudent(int id) {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String sql = "DELETE FROM students WHERE id = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setInt(1, id);
            int rowsDeleted = stmt.executeUpdate();
            return rowsDeleted > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    private static class Student {
        int id;
        String name;
        int age;

        public Student(int id, String name, int age) {
            this.id = id;
            this.name = name;
            this.age = age;
        }
    }
}*/
