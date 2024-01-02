<%-- 
    Document   : list
    Created on : 21 sept 2023, 18:12:46
    Author     : alumne
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="database.OperateDB" %>
<%@page import="java.util.List" %>
<%@page import="java.util.ArrayList" %>

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
        <link rel="stylesheet" href="styles/list.css?version=2">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <title>listar</title>
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
             <h1> Image Gallery </h1>
             <div class="image-container">
                  <%
                      List<String[]> imageList = OperateDB.getAllImages();
                      session.setAttribute("result", imageList); 
                      String username = session.getAttribute("username").toString();
                      out.println("<input type='hidden' id='username' value="+username+">"); 
                      int total = imageList.size(); 
                      
                          for (int i = 0; i < total; ++i) {
                            String [] imageInfo = imageList.get(i);
                            out.println("<input type='hidden' id='image-title"+i+"' value='"+imageInfo[1]+"'>"); 
                            out.println("<div class=\"image\"> <img src=http://localhost:8080/PRACTICA2/images/"+imageInfo[8]+" alt="+imageInfo[5]+" longdesc="+i+"/> </div>"); //alt = creador de la imagen ; longdesc = posicion en la lista. 
                          } 
                    %>
             </div>  
             <div class="popup">
                <span>&times;</span> 
                <img src="" alt="">
                <div class="metadatos">
                    <h2> <!-- se agrega el titulo de la imagen dinamicamente --> </h2>
                </div>     
                <div class="form-container" id="form-container">
                    <!-- se agregara el form hacia modificar o eliminar dinamicamente si se cumple la condición --> 
                </div>
             </div>
        </div>
  
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
             
    </body>
    
    <!-- script para el popup de la imagen i mostrar los botones de modificar y eliminar si es necesario --> 
    <script>
    
        document.querySelectorAll('.image-container img').forEach(image =>{
            
            image.onclick = () =>{
                
                var longdescValue = image.getAttribute("longdesc");
                var entero = parseInt(longdescValue, 10); 
                var title = document.getElementById("image-title"+entero+"").value; 
                var username = document.getElementById("username").value; 
                
                document.querySelector('.popup').style.display = 'block'; 
                document.querySelector('.popup img').src = image.getAttribute('src');    
                document.querySelector('.popup .metadatos h2').textContent = title; 
                
                if (image.getAttribute('alt') === username) {
                    
                    var formContainer = document.getElementById("form-container"); 
                
                    //Creamos el formulario 
                    var form = document.createElement("form"); 
                    form.action = "result";
                    form.method = "POST"; 
                    
                    //Creamos boton de link a modificar imagen. 
                    var modify = document.createElement("button"); 
                    modify.name = "button"; 
                    modify.value = "modify"; 
                    modify.type = "submit"; 
                    modify.innerHTML = "Modify"; 
                    modify.classList.add("form-btn-modify"); 
                    
                    //Creamos boton de link a eliminar imagen. 
                    var erase = document.createElement("button"); 
                    erase.name = "button"; 
                    erase.value = "erase"; 
                    erase.type = "submit"; 
                    erase.innerHTML = "Delete"; 
                    erase.classList.add("form-btn"); 
                    
                    
                    //Creamos el input type vacio 
                    var hiddenInput = document.createElement("input"); 
                    hiddenInput.type = "hidden"; 
                    hiddenInput.name = "id"; 
                    hiddenInput.value = entero; 
                    
                    //Agregamos los botones al formulario 
                    form.appendChild(modify);
                    form.appendChild(erase);
                    form.appendChild(hiddenInput); 
                    form.classList.add("MandE"); 
                    
                    // Agregamos el formulario al contenedor
                    formContainer.appendChild(form);
                }
            }; 
        });

        document.querySelector('.popup span').onclick = () =>{
            document.querySelector('.popup').style.display = 'none';

            var formContainer = document.getElementById("form-container"); 
            formContainer.innerHTML = ''; 

        };         
    </script> 
</html>
<% } %>

    
