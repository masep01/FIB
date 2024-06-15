<%-- 
    Document   : login
    Created on : 19 sept 2023, 10:48:03
    Author     : Santi&Josep
--%>
<%
    session.invalidate();
%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel="stylesheet" href="styles/login.css?version=1">
    </head>
    <body>
        <div class="wrapper">
            <h2>Login</h2>
            <form action="login" method = "POST">
                
                <div class="input-box">
                    <input type="text" name="uname" placeholder="Write your username" required>
                </div>  
                <div class="input-box">
                    <input type="password" name="pw" placeholder="Write your password" required>
                </div>
                <div class="input-box button">
                    <input type="Submit" value="Login">
                </div>
                <div class="text">
                <h3>Not registered yet? <a href="register.jsp">Sign Up</a> </h3> 
                </div>
            </form>
        </div>
    </body>
</html>
