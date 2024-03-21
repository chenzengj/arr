package JDBC_1;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * @AUTHOR czj
 * package_name JDBC_1
 * @DATE 2024/3/20 19:23
 */




public class JDBCUtilsTest {

    public static void main(String[] args) {
        List<Student> list = findAll();
        System.out.println("list = " + list);
    }

    //定义一个方法，查询user表的数据将其封装为对象，然后装载集合，返回。
    public static List<Student> findAll(){
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;
        List<Student> list = null;
        try {
            conn = JDBCUtils.getConnection();//获取连接
            //定义sql
            String sql = "SELECT * FROM student";
            //获取执行sql的对象
            st = conn.createStatement();
            //执行sql
            rs = st.executeQuery(sql);
            Student stu = null;
            list = new ArrayList<Student>();
            while (rs.next()){
                int id = rs.getInt("id");//获取该行的id数值
                String name=rs.getString("name");//获取该行的name
                int age=rs.getInt("age");
                Date birthday=rs.getDate("birthday");
                stu = new Student(id,name,age,birthday);
                list.add(stu);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.close(rs,st,conn);//释放资源
        }
        return list;
    }
}

