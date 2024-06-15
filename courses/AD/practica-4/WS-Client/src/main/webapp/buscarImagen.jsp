<%-- 
    Document   : buscarImagen
    Created on : 21 sept 2023, 18:13:05
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
        <link rel="stylesheet" href="styles/buscarImagen.css?version=8">
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
                <h1>Search an image</h1>
                
                <h2>Filters 
                    <span class="info-icon">
                        <i class="material-icons">info</i>
                        <div class="info-card">
                            <p>Please fill one or more fields</p>
                        </div>
                    </span>
                </h2>
                
                <form id="myForm" action="buscarImagen" method="POST">
                    <div class="input-icons">
                        <i class="material-icons">title</i> 
                        <input id="title" type="text" name="title" placeholder="Write the image title">
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">description</i> 
                        <input id="desc" type="text" name="desc" placeholder="Write a description">
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">key</i> 
                        <input id="keywords" type="text" name="keywords" placeholder="Write keywords">
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">person</i> 
                        <input id="author" type="text" name="author" placeholder="Write the author">
                    </div>
                    <div class="input-icons">
                        <i class="material-icons">calendar_month</i>
                        <input class="date-input" id="creationDate" type="date" name="creationDate" placeholder="Write the date">
                    </div>
                    <button class="btn" type="submit">SEARCH</button>
                </form>         
            </div> 
        </div>
    </body>
    <footer>
        <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
    </footer>
    <script>
        /* Show a info card when passing the mouse over the icon */
        const infoIcon = document.querySelector('.info-icon');

        infoIcon.addEventListener('mouseover', () => {
          const infoCard = document.querySelector('.info-card');
          infoCard.style.display = 'flex';
        });

        infoIcon.addEventListener('mouseout', () => {
          const infoCard = document.querySelector('.info-card');
          infoCard.style.display = 'none';
        });
        
        /* Check that the user has filled one field at least */
        document.getElementById("myForm").addEventListener("submit", function (event){
            var title = document.getElementById("title").value;
            var desc = document.getElementById("desc").value;
            var keywords = document.getElementById("keywords").value;
            var author = document.getElementById("author").value;
            var date = document.getElementById("creationDate").value;
            if(title === "" && desc === "" && keywords === "" && author === "" && date === ""){
                alert("Please, fill one field at least"); 
                event.preventDefault();
            }
        });
    </script>
</html>
<% } %>