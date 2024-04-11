package com.example.dao;
import com.example.entity.User;
import com.example.util.DBUtil;

import java.sql.*;

/**
 * @AUTHOR czj
 * package_name com.example.dao
 * @DATE 2024/4/8 19:27
 */


public class UserDaoImpl implements UserDao {

    @Override
    public User findUserByUsername(String username) throws SQLException {

        User user = null;
        Connection conn = DBUtil.getConnection();
        String sql = "SELECT * FROM user WHERE username = ?";
        try ( PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, username);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                user = new User();
                user.setId(rs.getInt("id"));
                user.setUsername(rs.getString("username"));
                user.setPassword(rs.getString("password"));
                user.setEmail(rs.getString("email"));
                user.setFailedAttempts(rs.getInt("failed_attempts"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return user;
    }

    @Override
    public boolean registerUser(User user) throws SQLException {
        Connection conn = DBUtil.getConnection();
        String sql = "INSERT INTO user (username, password, email) VALUES (?, ?, ?)";
//        Statement stat = conn.createStatement();
//        int count=stat.executeUpdate(sql);
//        System.out.println(count);
        try ( PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, user.getUsername());
            stmt.setString(2, user.getPassword());
            stmt.setString(3, user.getEmail());
            System.out.println(stmt.executeUpdate());
            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    @Override
    public boolean updateFailedAttempts(String username, int failedAttempts) throws SQLException {
        Connection conn = DBUtil.getConnection();
        String sql = "UPDATE user SET failed_attempts = ? WHERE username = ?";
        try ( PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, failedAttempts);
            stmt.setString(2, username);
            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
    public boolean updatePassword(User user) throws SQLException {
        Connection conn = DBUtil.getConnection();
        String sql = "UPDATE user SET password = ? WHERE id = ?";

        try ( PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, user.getPassword());
            stmt.setInt(2, user.getId());
            return stmt.executeUpdate() > 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
}
