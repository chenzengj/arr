package com.example.dao;
import com.example.entity.User;

import java.sql.SQLException;

/**
 * @AUTHOR czj
 * package_name com.example.dao
 * @DATE 2024/4/8 15:21
 */


public interface UserDao {
    User findUserByUsername(String username) throws SQLException;
    boolean registerUser(User user) throws SQLException;
    boolean updateFailedAttempts(String username, int failedAttempts) throws SQLException;
    boolean updatePassword(User user) throws SQLException;
}
