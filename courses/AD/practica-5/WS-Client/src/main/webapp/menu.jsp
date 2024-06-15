<%-- 
    Document   : menu
    Created on : 19 sept 2023, 10:48:41
    Author     : alumne
--%>


<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <%
        if(session.getAttribute("username") == null){
            session.setAttribute("errorMessage", "User not identified");
            response.sendRedirect("error.jsp");
            response.flushBuffer();
        } else {
    %>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel="stylesheet" href="styles/menu.css?version=1">
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
        <div class="container">
            <div class="hub">
                <span>Photo</span>
                <span>Hub</span>
            </div>
        </div>
        <div class="boxer">
            <div class="box">
                <a href="registrarImagen.jsp">
                    <img src="https://icons.veryicon.com/png/o/miscellaneous/1em/add-image.png" width="60px"/>
                    <span>Add an image</span>
                </a>
            </div>
            <div class="box">
                <a href="list.jsp">
                    <img src="https://cdn0.iconfinder.com/data/icons/rounded-basics/24/svg-rounded_list-512.png" width="60px"/>
                    <span>List images</span>
                </a>
            </div>
            <div class="box">
                <a href="buscarImagen.jsp">
                    <img src="https://www.iconpacks.net/icons/2/free-search-icon-3076-thumb.png" width="60px"/>
                    <span>Search an image</span>
                </a>
            </div>
        </div>      
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
</html>
<% } %>