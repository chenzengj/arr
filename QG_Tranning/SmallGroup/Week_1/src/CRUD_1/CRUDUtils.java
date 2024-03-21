package CRUD_1;

/**
 * @AUTHOR czj
 * package_name CRUD_1
 * @DATE 2024/3/19 17:54
 */
import JDBC_1.JDBCUtils;
import JDBC_1.Student;
import java.util.Date;

import java.sql.*;
import java.text.SimpleDateFormat;

public class CRUDUtils {
    public static Connection getConnection() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return conn;
    }
    /*
    条件查询，根据id查询学生信息
*/

public static Student findById(int sid) {
    Student stu = new Student();
    Connection conn = null;
    Statement stat = null;
    ResultSet rs = null;
    try{
        conn = JDBCUtils.getConnection();
        //注册驱动，获取数据库连接

        //获取执行者对象
        stat = conn.createStatement();

        //执行sql语句，并且接收返回的结果集
        String sql = "SELECT * FROM student WHERE id='"+sid+"'";
        rs = stat.executeQuery(sql);

        //处理结果集
        while(rs.next()) {
            int id = rs.getInt("id");
            String name = rs.getString("name");
            int age = rs.getInt("age");
            Date birthday = rs.getDate("birthday");

            //封装Student对象
            stu.setId(id);
            stu.setName(name);
            stu.setAge(age);
            stu.setBorn(birthday);
        }

    } catch(Exception e) {
        e.printStackTrace();
    } finally {
        //释放资源
        JDBCUtils.close(rs,stat,conn);
    }
    //将对象返回
    return stu;
}
/*
      添加学生信息
*/
public static int insert(Student stu) throws Exception {
    Connection conn =null;
    Statement stat = null;
    int result = 0;
    try{
       conn = JDBCUtils.getConnection();
       //注册驱动，获取数据库连接


        //获取执行者对象
        stat = conn.createStatement();

        //执行sql语句，并且接收返回的结果集
        Date d = (Date) stu.getBorn();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String birthday = sdf.format(d);
        String sql = "INSERT INTO student VALUES ('"+stu.getId()+"','"+stu.getName()+"','"+stu.getAge()+"','"+birthday+"')";
        result = stat.executeUpdate(sql);

    } catch(Exception e) {
        e.printStackTrace();
    } finally {
        //释放资源
        JDBCUtils.close(stat,conn);
    }
    //将结果返回
    return result;
}
    /*
        修改学生信息
    */

    public static int update(Student stu) throws Exception {
        Connection conn=null;
        Statement stat = null;
        int result = 0;
        try{
           conn = JDBCUtils.getConnection();
            //注册驱动，获取数据库连接

            //获取执行者对象
            stat = conn.createStatement();

            //执行sql语句，并且接收返回的结果集
            Date d = stu.getBorn();
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");//时间格式要求
            String birthday = sdf.format(d);
            String sql = "UPDATE student SET id='"+stu.getId()+"',name='"+stu.getName()+"',age='"+stu.getAge()+"',birthday='"+birthday+"' WHERE id='"+stu.getId()+"'";
            result = stat.executeUpdate(sql);

        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            //释放资源
            JDBCUtils.close(stat,conn);
        }
        //将结果返回
        return result;
    }
    /*
       删除学生信息
    */

    public static int delete(int id) {
        Connection conn = null;
        Statement stat = null;
        int result = 0;
        try{
            conn = JDBCUtils.getConnection();

            //获取执行者对象
            stat = conn.createStatement();

            //执行sql语句，并且接收返回的结果集
            String sql = "DELETE FROM student WHERE id='"+id+"'";
            result = stat.executeUpdate(sql);

        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            //释放资源
            JDBCUtils.close(stat,conn);
        }
        //将结果返回
        return result;
    }

}




