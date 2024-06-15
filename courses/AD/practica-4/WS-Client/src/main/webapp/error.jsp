<%-- 
    Document   : error
    Created on : 21 sept 2023, 11:36:38
    Author     : alumne
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2: Error</title>
        <link rel="stylesheet" href="styles/error.css?version=1">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    </head>
    <body>
        <nav>
            <a class="logout" href="login.jsp">
                <i class="material-icons">logout</i>
            </a>
        </nav>
        <div class="main">
            <div class="container">
                <h1>Something went wrong...</h1>
                <h2>Error: <% out.println((String)session.getAttribute("errorMessage"));%></h2>
                <br>
                <a class="ref" href="login.jsp">Login</a>
            </div>
        </div>
    </body>
    <footer>
        <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
    </footer>
    <% session.invalidate(); %>
</html>

