package JDBC_1;

import java.io.*;
import java.sql.*;
import java.util.Properties;

/**
 * @AUTHOR czj
 * package_name JDBC_1
 * @DATE 2024/3/20 18:54
 */
public class JDBCUtils {
    private static String driver = null;
    private static String url = null;
    private static String user = null;
    private static String password = null;
    static {
        try {
            // 1.创建一个属性配置对象,使用Properties处理流
            Properties properties = new Properties();
            // 导入输入流
             InputStream is = new FileInputStream("src\\db.properties");
            //Reader is =new FileReader("db.properties");
            //InputStream is=JDBCUtil.class.getClassLoader().getResourceAsStream("db.properties");
            //load() 这个方法可以从.properties属性文件 对应的文件输入流中,加载属性列表到Properties类对象。
            properties.load(is);
            // 读取属性
            driver = properties.getProperty("driver");
            url = properties.getProperty("url");
            user = properties.getProperty("username");
            password = properties.getProperty("password");
            Class.forName(driver);

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    //获得链接
    public static Connection getConnection()throws SQLException{
        try{
            //1.注册驱动
            Class.forName(driver);
            //2.获得连接
            Connection conn= DriverManager.getConnection(url,user,password);
            return conn;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    /**
     * 释放资源
     */
    public static void close(ResultSet rs, Statement st,Connection conn){
        if(rs!=null){
            try{
                rs.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if(st!=null){
            try{
                st.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if (conn!=null){
            try{
            conn.close();
        }catch (SQLException e){
            e.printStackTrace();
        }}
    }
    public static void close(Statement st,Connection conn){
       close(null,st,conn);
    }
}
