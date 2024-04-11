package com.example.controller;

import com.example.BaseServlet;
import com.example.service.UserService;
import com.example.service.UserServiceImpl;
import com.example.util.JsonUtil;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

/**
 * @AUTHOR czj
 * package_name com.example.controller
 * @DATE 2024/4/10 16:10
 */

public class ResetPasswordServlet extends BaseServlet {

    private UserService userService = new UserServiceImpl();

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String newPassword = req.getParameter("newPassword");

        Map<String, Object> result = new HashMap<>();
        try {
            if (userService.resetPassword(username, newPassword)) {
                result.put("success", true);
            } else {
                result.put("success", false);
                result.put("message", "Password reset failed");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        resp.setContentType("application/json");
        resp.getWriter().write(JsonUtil.toJson(result));
    }
}
