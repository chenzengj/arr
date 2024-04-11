package com.example;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Method;

/**
 * @AUTHOR czj
 * package_name com.example
 * @DATE 2024/4/9 13:25
 */

public class BaseServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        try {
            // 获取请求方法
            String methodName = req.getParameter("method");
            if (methodName == null || methodName.trim().isEmpty()) {
                methodName = "execute";
            }

            // 获取方法对象
            Method method = this.getClass().getDeclaredMethod(methodName, HttpServletRequest.class, HttpServletResponse.class);

            // 执行方法
            method.invoke(this, req, resp);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void execute(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 默认执行方法，可以被子类覆盖
    }
}
