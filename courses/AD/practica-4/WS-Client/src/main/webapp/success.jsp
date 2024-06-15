<%-- 
    Document   : registerSuccess
    Created on : 23 sept 2023, 13:34:10
    Author     : alumne
--%>
<% 
    if(session.getAttribute("username") == null){
        session.setAttribute("errorMessage", "User not identified");
        response.sendRedirect("error.jsp");
        response.flushBuffer();  
    } else {
%> 
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel='stylesheet' href='styles/success.css?version=2'>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    </head>
    <body>
        <nav>
           <a class="logout" href="login.jsp">
               <i class="material-icons">logout</i>
           </a>
           <a class="active" href="menu.jsp">
               <i class="material-icons">home</i> 
           </a>
           <div class="welcome">
           <%
               out.print("Welcome <strong>"+ session.getAttribute("username")+"</strong> !");
           %>
           </div>
        </nav>
        <div class='main'>
            <div class="container">
                <% out.println("<h2>"+(String)session.getAttribute("successMessage")+"</h2>");%>
                <% session.removeAttribute("successMessage");%>        
                <a class ="ref" href='registrarImagen.jsp'>Upload more images</a>  
                <br>
                <a class ="ref" href='menu.jsp'>Menu</a>
            </div>
        </div>
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
</html>
<% } %>