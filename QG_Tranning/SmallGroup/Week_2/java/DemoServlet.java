/**
 * @AUTHOR czj
 * package_name PACKAGE_NAME
 * @DATE 2024/3/27 21:18
 */
import java.io.IOException;
import java.util.Map;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
 * @AUTHOR czj
 * package_name PACKAGE_NAME
 * @DATE 2024/3/26 13:08
 */
@WebServlet(urlPatterns = {"/demo"})
public class DemoServlet extends HttpServlet {
        @Override
        protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
            // 处理GET请求的逻辑
            String name = request.getParameter("name");
            response.getWriter().println("Hello, " + name);
        }

        @Override
        protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
            // 处理POST请求的逻辑
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            // 执行对服务器端数据的修改操作
            // ...
            response.getWriter().println("Data updated successfully");
        }

//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        // GET请求处理
//        response.setContentType("test/html;charset=UTF-8");
//        response.setStatus(HttpServletResponse.SC_OK);
//        response.getWriter().write("GET...");
//    }
//
//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        // POST请求处理
//        response.setContentType("text/plain");
//        response.setStatus(HttpServletResponse.SC_CREATED); // 201 Created
//        response.getWriter().println("POST ....");
//    }
//@Override
//protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//    resp.setContentType("text/html;charset=utf-8");
//    //GET请求逻辑
//    System.out.println("get....");
//
//    //1. 获取所有参数的Map集合
//    Map<String, String[]> map = req.getParameterMap();
//    for (String key : map.keySet()) {
//        // 例如username:zhangsan lisi
//        System.out.print(key+":");
//
//        //获取值，遍历数组
//        String[] values = map.get(key);
//        for (String value : values) {
//            System.out.print(value + " ");
//        }
//
//        System.out.println();  //换行
//    }
//
//    System.out.println("------------");
//
//    //2. 根据key获取参数值，数组
//    String[] hobbies = req.getParameterValues("hobby");
//    for (String hobby : hobbies) {
//
//        System.out.println(hobby);
//    }
//
//    //3. 根据key 获取单个参数值
//    String username = req.getParameter("username");
//    String password = req.getParameter("password");
//
//    System.out.println(username);
//    System.out.println(password);
//}

//    @Override
//    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        //POST请求逻辑
//        System.out.println("post...");
//
//        this.doGet(req,resp);
//    }

    protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // PUT请求处理
        response.setStatus(HttpServletResponse.SC_NO_CONTENT); // 204 No Content
        // 无响应体
    }

    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // DELETE请求处理
        response.setStatus(HttpServletResponse.SC_ACCEPTED); // 202 Accepted
        response.getWriter().println("DELETE 请求已接受");
    }

    protected void doOptions(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // OPTIONS请求处理
        response.setStatus(HttpServletResponse.SC_OK); // 200 OK
        response.setHeader("Allow", "GET, POST, PUT, DELETE, OPTIONS"); // 允许的HTTP方法
    }

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 处理其他HTTP方法
        response.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 405 Method Not Allowed
        response.getWriter().println("不支持的HTTP方法");
    }
}
