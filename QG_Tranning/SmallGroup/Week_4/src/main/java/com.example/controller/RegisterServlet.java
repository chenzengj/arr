package com.example.controller;

import com.example.BaseServlet;
import com.example.entity.User;
import com.example.service.UserService;
import com.example.service.UserServiceImpl;
import com.example.util.JsonUtil;
import com.google.gson.Gson;
import com.google.gson.JsonObject;

import javax.servlet.ServletException;
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
 * @DATE 2024/4/9 20:35
 */

public class RegisterServlet extends BaseServlet {

    private UserService userService = new UserServiceImpl();

    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
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
        String email = jsonObject.get("email").getAsString();


        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        user.setEmail(email);

        Map<String, Object> result = new HashMap<>();
        try {
            if (userService.register(user)) {
                result.put("success", true);
            } else {
                result.put("success", false);
                result.put("message", "Registration failed");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        resp.setContentType("application/json");
        resp.getWriter().write(JsonUtil.toJson(result));
    }
}
