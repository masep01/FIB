<%-- 
    Document   : registersuccess
    Created on : 28 sept 2023, 17:16:30
    Author     : alumne
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <%
        if(session.getAttribute("successMessage") == null){
            session = request.getSession(true);
            session.setAttribute("errorMessage", "User not identified");
            response.sendRedirect("error.jsp");
            response.flushBuffer();
        } else {
            
    %>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel='stylesheet' href='styles/registerSuccess.css?version=1'>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    </head>
    <body>
        <nav>
           <a class="logout" href="login.jsp">
               <i class="material-icons">logout</i>
           </a>
           <a class="active" href="login.jsp">
               <i class="material-icons">home</i> 
           </a>
        </nav>
        <div class='main'>
            <div class="container">
                <% out.println("<h2>"+(String)session.getAttribute("successMessage")+"</h2>");%>
                <% session.removeAttribute("successMessage");%>
                <a class ="ref" href='login.jsp'>Login</a>  
            </div>
        </div>
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
</html>
<% } %>