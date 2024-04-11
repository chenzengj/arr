<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Reset Password</title>
    <link rel="stylesheet" href="css/style.css">
    <script src="js/jquery-3.7.1.js"></script>
    <script src="js/main.js"></script>
</head>
<body>
<h1>重置密码</h1>
<form>
    <label>
        用户名:
        <input type="text" id="username" name="username">
    </label>
    <br>
    <label>
        新密码:
        <input type="password" id="newPassword" name="newPassword">
    </label>
    <br>
    <button type="button" onclick="resetPassword()">重置密码</button>
</form>
<div id="result"></div>
</body>
</html>