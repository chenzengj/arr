<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Login</title>
    <link rel="stylesheet" href="css/style.css">

    <script src="js/jquery-3.7.1.js"></script>
    <script src="js/main.js"></script>

</head>
<body>
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
    <button type="button" onclick="login()">登录</button>
</form>
<div id="result"></div>
</body>
</html>
</body>
</html>
