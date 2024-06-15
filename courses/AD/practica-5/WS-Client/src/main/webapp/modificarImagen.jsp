<%-- 
    Document   : modificarImagen
    Created on : 21 sept 2023, 18:12:28
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
            /* Retrieve image's data */
            String imageInfo[] = (String[])session.getAttribute("imageInfo");
            if(imageInfo != null) { 
                /* Verify that the client is actually the image's creator */
                if(!imageInfo[5].equals(session.getAttribute("username"))){
                    session.setAttribute("errorMessage", "Error trying to update image values");
                    response.sendRedirect("error.jsp");
                }    
    %>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel="stylesheet" href="styles/modificarImagen.css?version=3">
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
        <div class="main">
            <div class="container">
                <h1>Modify an image</h1>
                <div class="image">
                    <% out.print("<img src='images/"+imageInfo[8]+"' width='300px'/>");%>
                </div>
                <form action="modificarImagen" method="POST">
                    <div class="input-icons">
                        <i class="material-icons">title</i> 
                        <input type='text' name='new_title' value=<% out.print("'"+imageInfo[1]+"'");%>>
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">description</i> 
                        <input type='text' name='new_desc' value=<% out.print("'"+imageInfo[2]+"'");%>>
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">key</i> 
                        <input type='text' name='new_keywords' value=<% out.print("'"+imageInfo[3]+"'");%>>
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">person</i> 
                        <input type='text' name='new_author' value=<% out.print("'"+imageInfo[4]+"'");%>>
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">calendar_month</i>
                        <input class="date-input" type='date' name='new_cDate' value=<% out.print("'"+imageInfo[6]+"'");%>>
                    </div>
                    <button class="btn" type="submit">MODIFY</button>
                </form> 
            </div>
        </div>
        <footer>
           <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
</html>
<%  
    } else {
        session.setAttribute("errorMessage", "User not identified");
            response.sendRedirect("error.jsp");
            response.flushBuffer();
    }
} 
%>