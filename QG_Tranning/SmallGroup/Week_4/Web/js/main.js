
$(document).ready
    function login() {
    var username = $("#username").val();
    var password = $("#password").val();
    if(!username||!password){
        alert('please input ')
    return;}
    $.ajax({
        url: "http://localhost:8080/unnamed/login",
        type: "POST",

        data:  JSON.stringify({ username: username, password: password }), // 请求参数,JSON 格式
       // dataType: 'json',
        contentType: "application/json", // 请求内容类型
        success: function(data) {
            if (data.success) {
                $("#result").html("ok！");
            } else {
                // $("#result").html("登录成功");
                alert("response is wrong");
            }
        },
        error: function() {
            $("#result").html("wrong.");
        }
    });
}
function resetPassword() {
    var username = $("#username").val();
    var newPassword = $("#newPassword").val();

    $.ajax({
        url: "http://localhost:8080/unnamed/resetPassword",
        type: "POST",
        //dataType: 'json',
        data: {
            method: "resetPassword",
            username: username,
            newPassword: newPassword
        },
        success: function(data) {
            if (data.success) {
                // $("#result").html("密码重置成功!");
                alert("response is ok");

            } else {
                $("#result").html(data.message);
            }
        },
        error: function() {
            $("#result").html("重置失败.");
        }
    });
}
function register() {
    var username = $("#username").val();
    var password = $("#password").val();
    var email = $("#email").val();

    $.ajax({
        url: "http://localhost:8080/unnamed/register",
        type: "POST",
        //dataType: 'json',
        data:JSON.stringify({ username: username, password: password,email:email }), // 请求参数,JSON 格式
        contentType: "application/json", // 请求内容类型
        success: function(data) {
            if (data.success) {
                $("#result").html("注册成功!");
                alert("response is ok");

            } else {
                $("#result").html(data.message);
                alert("wrong");
            }
        },
        error: function() {
            alert("3");
            $("#result").html("wrong.");
        }
    });
}