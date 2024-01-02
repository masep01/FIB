<%-- 
    Document   : eliminarImagen
    Created on : 21 sept 2023, 18:12:22
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
            
            String imageInfo[] = (String[])session.getAttribute("imageInfo"); 
            if (imageInfo == null) {
                session.setAttribute("errorMessage", "Invalid session");
                response.sendRedirect("error.jsp");
            }
            
            else {
                if(!imageInfo[5].equals(session.getAttribute("username"))){
                    session.setAttribute("errorMessage", "Error trying to update image values");
                    response.sendRedirect("error.jsp");
                }
    %>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" href="styles/eliminarImagen.css?version=3">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <title>Practica 2</title>
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
                <h1>Delete an image</h1>
                <div class="imageWrapper">
                    <% out.print("<img id='image' src='http://localhost:8080/PRACTICA2/images/"+imageInfo[8]+"' width=60%/>"); %>
                    <table id="tabla">
                        <tr>
                            <th>TITLE</th> 
                            <% out.println("<td>"+imageInfo[1]+"</td>"); %>
                        </tr>
                        <tr>
                            <th>DESCRIPTION</th> 
                            <% out.println("<td>"+imageInfo[2]+"</td>"); %>
                        </tr>
                        <tr>
                            <th>KEYWORDS</th> 
                            <% out.println("<td>"+imageInfo[3]+"</td>"); %>
                        </tr>
                        <tr>
                            <th>AUTHOR</th> 
                            <% out.println("<td>"+imageInfo[4]+"</td>"); %>
                        </tr> 
                        <tr>
                            <th>CAPTURE DATE</th> 
                            <% out.println("<td>"+imageInfo[6]+"</td>"); %>
                        </tr> 
                    </table>
                </div>
                <div class="btnwrapper">
                    <form action="eliminarImagen" method="POST" id="formulario">
                        <button class="btn" id="deleteButton" type="submit">DELETE</button> 
                    </form> 
                </div>        
            </div>
        </div>
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
    
    <script> 
        // Funcion para que la tabla sea igual de ancha que la imagen. 
        window.onload = function() {
            
            // Obtener la referencia a la imagen y a la tabla 
            var imagen = document.getElementById("image"); 
            var tabla = document.getElementById("tabla"); 
            
            // Obtener el ancho actual de la imagen 
            var anchoImagen = imagen.clientWidth; 
            
            // Establecer ancho de la imagen igual que el de la tabla. 
            tabla.style.width = anchoImagen + "px"; 
        }
    
        document.getElementById("deleteButton").addEventListener("click", function() {
            //Funcion para añadir un mensaje de aviso antes de borrar
            var confirmacion = confirm("Are you sure you sure you want to delete?");
            var formulario = document.getElementById("formulario"); 
           
            if (!confirmacion) {
                alert("Deletion canceled"); 
                formulario.action = "eliminarImagen.jsp"; 
            }
        }); 
    </script>
</html>
<% } %> 
<%} %>
