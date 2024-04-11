package com.example.service;

import com.example.dao.UserDao;
import com.example.dao.UserDaoImpl;
import com.example.entity.User;
import com.example.util.StringUtil;

import java.sql.SQLException;

/**
 * @AUTHOR czj
 * package_name com.example.service
 * @DATE 2024/4/8 20:47
 */

public class UserServiceImpl implements UserService {

    private UserDao userDao = new UserDaoImpl();

    @Override
    public boolean authenticate(String username, String password) throws SQLException {
        User user = userDao.findUserByUsername(username);
        if (user != null && user.getPassword().equals(password)) {
            return true;
        } else {
            incrementFailedAttempts(username);
            return false;
        }
    }

    @Override
    public boolean register(User user) throws SQLException {
        String username = user.getUsername();
        String password = user.getPassword();
        String email = user.getEmail();

//        // 检查用户名、密码和邮箱是否合法
//        if (!isValidUsername(username) || !isValidPassword(password) || !isValidEmail(email)) {
//            return false;
//        }
//
//        // 检查是否包含敏感词
//        if (StringUtil.containsSensitiveWords(username) || StringUtil.containsSensitiveWords(password)) {
//            return false;
//        }

        // 注册用户
        return userDao.registerUser(user);
    }

    @Override
    public void incrementFailedAttempts(String username) throws SQLException {
        User user = userDao.findUserByUsername(username);
        if (user != null) {
            int failedAttempts = user.getFailedAttempts() + 1;
            userDao.updateFailedAttempts(username, failedAttempts);
        }
    }

    private boolean isValidUsername(String username) {
        // 实现用户名合法性检查的逻辑
        return true;
    }

    private boolean isValidPassword(String password) {
        // 实现密码合法性检查的逻辑
        return true;
    }

    private boolean isValidEmail(String email) {
        // 实现邮箱合法性检查的逻辑
        return true;
    }
    public boolean resetPassword(String username, String newPassword) throws SQLException {
        User user = userDao.findUserByUsername(username);
        if (user != null) {
            // 检查新密码是否合法
            if (!isValidPassword(newPassword)) {
                return false;
            }
            // 更新密码
            user.setPassword(newPassword);
            return userDao.updatePassword(user);
        }
        return false;
    }
}
