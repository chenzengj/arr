package com.example.controller;

import com.example.BaseServlet;
import com.example.service.UserService;
import com.example.service.UserServiceImpl;
import com.example.util.JsonUtil;
import com.google.gson.Gson;
import com.google.gson.JsonObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

/**
 * @AUTHOR czj
 * package_name com.example.controller
 * @DATE 2024/4/9 19:27
 */

public class LoginServlet extends BaseServlet {

    private UserService userService = new UserServiceImpl();

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        StringBuilder buffer = new StringBuilder();
        BufferedReader reader = req.getReader();
        String line;
        while ((line = reader.readLine()) != null) {
            buffer.append(line);
        }
        String payload = buffer.toString();

        Gson gson = new Gson();
        JsonObject jsonObject = gson.fromJson(payload, JsonObject.class);
        String username = jsonObject.get("username").getAsString();
        String password = jsonObject.get("password").getAsString();

        // 调用 UserService 进行认证
        //boolean isAuthenticated = userService.authenticate(username, password);
        Map<String, Object> result = new HashMap<>();
        try {
            if (userService.authenticate(username, password)) {
                result.put("success", true);
            } else {
                result.put("success", false);
                result.put("message", "Invalid username or password");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        resp.setContentType("application/json");
        resp.getWriter().write(JsonUtil.toJson(result));

//        if (isAuthenticated) {
//            // 认证成功,返回成功响应
//            resp.setStatus(HttpServletResponse.SC_OK);
//
//        } else {
//            // 认证失败,返回错误响应
//            resp.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
//        }
//
    }
//        System.out.println("888");
//        String username = req.getParameter("username");
//        String password = req.getParameter("password");
//        System.out.println("aaa");
//        Map<String, Object> result = new HashMap<>();
//        if (userService.authenticate(username, password)) {
//            result.put("success", true);
//        } else {
//            result.put("success", false);
//            result.put("message", "Invalid username or password");
//        }
//
//        resp.setContentType("application/json");
//        resp.getWriter().write(JsonUtil.toJson(result));
    }

