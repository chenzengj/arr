<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Welcome</title>
    <link rel="stylesheet" href="css/style.css">
    <script src="js/jquery-3.7.1.js"></script>
    <script src="js/main.js"></script>
</head>
<body>
<h1>欢迎来到原神网站</h1>
<div>
    <h1>登录</h1>
    <form>
        <label>
            用户名:
            <input type="text" id="username" name="username" required>
        </label>
        <br>
        <label>
            密码:
            <input type="password" id="password" name="password" required>
        </label>
        <br>
        <button type="button" onclick="login()">Login</button>
    </form>
    <div id="result"></div>
<%--    <a href="login.jsp">登录</a>--%>
    <a href="register.jsp">注册</a>
    <a href="resetPassword.jsp">重置密码</a>
</div>
</body>
</html>

</body>
</html>
