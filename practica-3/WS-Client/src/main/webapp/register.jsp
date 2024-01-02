<%-- 
    Document   : register
    Created on : 28 sept 2023, 11:17:02
    Author     : alumne
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
       <link rel="stylesheet" type="text/css" href="styles/register.css">
    </head>
    <body>
        <div class="wrapper">
            <h2>Sign Up</h2>
            <form id="regForm" action="register" method="POST">
                <div class="input-box">
                    <input type="text" id="uname" name="uname" placeholder="Write your username" required>
                </div>
                <div class="input-box">
                    <input type="password" id="pw1" name="pw" minlength="7" maxlength="16" placeholder="Create password" required>
                    <span id="msg1"></span><br>
                </div>
                <div class="input-box">
                    <input type="password" id="pw2" name="pw2" minlength="7" maxlength="16" placeholder="Repeat password" required>
                    <span id="msg2"></span><br>
                </div>
                <div class="policy">
                    <input type="checkbox" id="termsandservices" required>
                    <h3>I accept all terms & condition</h3>
                </div>
                <div class="input-box button">
                    <input type="Submit" id="btn" value="Register">
                </div>
                <div class="text">
                    <h3>Already have an account? <a href="login.jsp">Login</a> </h3>
                </div>
            </form>
        </div>           
    </body>
   
    <script>
        document.getElementById("regForm").addEventListener("submit", function (event){
            var password = document.getElementById("pw1");
            var password2 = document.getElementById("pw2");
            var msg1 = document.getElementById("msg1");
            var msg2 = document.getElementById("msg2"); 
                
            if(password.value.search(/[a-z]/) < 0){
                msg1.textContent = "Password must contain at least one lowercase letter";
                event.preventDefault();
                
            } else if(password.value.search(/[A-Z]/) < 0){
                msg1.textContent = "Password must contain at least one uppercase letter";
                password.style.borderColor="#DC143C"; 
                password2.style.borderColor="#DC143C"; 
                event.preventDefault();
                
            } else if(password.value.search(/[0-9]/) < 0){
                msg1.textContent = "Password must contain at least one number";
                password.style.borderColor="#DC143C"; 
                password2.style.borderColor="#DC143C";
                event.preventDefault();
                
            } else {
                msg1.textContent = "";
                
            } if(password.value !== password2.value && msg1.textContent === ''){
                    msg2.textContent = "Passwords do not match"; 
                    password.style.borderColor="#DC143C"; 
                    password2.style.borderColor="#DC143C";
                    event.preventDefault();
            } else msg2.textContent = "";
              
        });
    </script>
</html>
