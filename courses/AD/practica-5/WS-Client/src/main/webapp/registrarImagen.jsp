<%-- 
    Document   : reigstrarImagen
    Created on : 21 sept 2023, 18:11:19
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
        <link rel="stylesheet" href="styles/registrarImagen.css?version=4">
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
            
        <!-- Navbar above -->    
        <div class="container">
            <div class="main">
                <div class="banner">
                    <img id="image-preview" src="https://hips.hearstapps.com/hmg-prod/images/nature-quotes-landscape-1648265299.jpg?crop=0.676xw:1.00xh;0.148xw,0&resize=640:*">
                </div>
                <div class="wrapper">
                    <h2>Upload an Image</h2>
                    <form action="registrarImagen" method = "POST" enctype="multipart/form-data">
                        <div class="input-box">
                            <!-- <label for="filefile>Title</label> -->
                            <input type="text" name="title" placeholder="Write the image title" required>
                        </div>
                        <div class="input-box">
                            <!-- <label for="filefile>Description</label> -->
                            <input type="text" name="desc" placeholder="Write a description" required>
                        </div>
                        <div class="input-box">
                            <!-- <label for="filefile>Keywords</label> -->
                            <input type="text" name="keywords" placeholder="Write keywords" required>
                        </div>
                        <div class="input-box">
                            <!-- <label for="filefile>Author</label> -->
                            <input type="text" name="author" placeholder="Write the author" required>
                        </div>
                        <div class="input-box">
                            <!-- <label for="filefile>Date</label> -->
                            <input type="date" name="creationDate" placeholder="Write the date" required>
                        </div>
                        <div class="selector" for="file">
                            <input type="file" id="file" name="file" required hidden/>
                            <label for="file">Choose a file</label>
                            <i class="material-icons">upload_file</i> 
                        </div>
                        <div class="btn">
                            <button type="submit">Upload</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
    <script>
        document.getElementById("file").addEventListener("change", function(event) {
            var input = event.target;
            var file = input.files[0];
            var reader = new FileReader();

            reader.onload = function() {
                var imagenPreview = document.getElementById("image-preview");
                imagenPreview.src = reader.result;
            };

            if (file) {
                reader.readAsDataURL(file);
            }
        });
    </script>
</html>
<% } %>