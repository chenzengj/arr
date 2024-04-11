package com.example.util;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @AUTHOR czj
 * package_name com.example.util
 * @DATE 2024/4/10 14:59
 */


public class DBConnectionPool {

    private static final String URL = "jdbc:mysql://localhost:3306/mydb";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "771015";
    private static final int MAX_CONNECTIONS = 10;

    private static List<Connection> connectionPool = new ArrayList<>();

    static {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            initializeConnections();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    private static void initializeConnections() throws SQLException {
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            Connection connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
            connectionPool.add(connection);
        }
    }

    public static Connection getConnection() throws SQLException {
        if (connectionPool.isEmpty()) {
            return DriverManager.getConnection(URL, USERNAME, PASSWORD);
        } else {
            return connectionPool.remove(0);
        }
    }

    public static void releaseConnection(Connection connection) {
        if (connection != null && connectionPool.size() < MAX_CONNECTIONS) {
            connectionPool.add(connection);
        }
    }
}