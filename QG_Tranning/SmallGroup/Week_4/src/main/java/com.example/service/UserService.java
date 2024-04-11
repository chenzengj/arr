package com.example.service;

import com.example.entity.User;

import java.sql.SQLException;

/**
 * @AUTHOR czj
 * package_name com.example.service
 * @DATE 2024/4/8 20:19
 */

public interface UserService {
    boolean authenticate(String username, String password) throws SQLException;
    boolean register(User user) throws SQLException;
    void incrementFailedAttempts(String username) throws SQLException;
    boolean resetPassword(String username, String newPassword) throws SQLException;
}
