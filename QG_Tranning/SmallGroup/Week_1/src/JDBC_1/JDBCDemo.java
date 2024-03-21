package JDBC_1;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
public class JDBCDemo {
    public static void main(String[] args) throws Exception {
        //1、导入驱动jar包
        //2、注册驱动
        Class.forName("com.mysql.cj.jdbc.Driver");

        //3、获取数据库的连接对象
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/db01", "root", "771015");

        //4、定义sql语句
        String sql = "INSERT INTO student VALUES(6,'smith',19,'2004-08-08')";


        //5、获取执行sql语句的对象
        Statement stat = con.createStatement();

        //6、执行sql并接收返回结果
        int count = stat.executeUpdate(sql);

        //7、处理结果
        System.out.println(count);

        //8、释放资源
        stat.close();
        con.close();
    }
}
