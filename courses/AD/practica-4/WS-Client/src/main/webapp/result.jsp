<%-- 
    Document   : result
    Created on : 25 sept 2023, 13:12:49
    Author     : alumne
--%>

<%@page import="java.util.*" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <%
        if(session.getAttribute("username") == null){
            session.setAttribute("errorMessage", "User not identified");
            response.sendRedirect("error.jsp");
            response.flushBuffer();
        } else {
            List<String[]> result = (List<String[]>)session.getAttribute("result");
            if(result != null) {
    %>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Practica 2</title>
        <link rel='stylesheet' href='styles/result.css?version=3'>
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
                <h1>Search results</h1>
                <table>
                    <tr>                    
                        <th>TITLE</th>
                        <th>DESCRIPTION</th>
                        <th>KEYWORDS</th>
                        <th>AUTHOR</th>       
                        <th>CAPTURE DATE</th>
                        <th>PREVIEW</th>
                    </tr>
                    <%
                        int nResults = 0;
                        for(int id = 0; id<result.size(); ++id){
                            String[] data = result.get(id);
                            out.println("<form action='result' method='POST'>");
                            out.println("<tr>");
                            out.println("<td>"+data[1]+"</td>");
                            out.println("<td>"+data[2]+"</td>");
                            out.println("<td>"+data[3]+"</td>");
                            out.println("<td>"+data[4]+"</td>");
                            out.println("<td>"+data[6]+"</td>");
                            out.println("<input type='hidden' name='id' value='"+id+"'></td>");
                            out.println("<td><img src='http://192.168.245.56:8080/PRACTICA2/images/"+data[8]+"' width='80px'/></td>");
                            if(session.getAttribute("username").equals(data[5])){
                                out.println("<td class='btn-cell'><button class='button modify-button hide-button' name='button' value='modify' type='submit'>Modify</button></td>");
                                out.println("<td class='btn-cell'><button class='button modify-button hide-button' name='button' value='remove' type='submit'>Remove</button></td>");
                            }
                            out.println("</tr>");
                            out.println("</form>");
                            ++nResults;
                        }
                        out.println(nResults + " results found");
                     %>
                </table>
            </div>  
        </div>
        <footer>
            <p>&copy; 2023 Santi & Josep @ AD Q1-2324</p>
        </footer>
    </body>
    <script>
        var rows = document.querySelectorAll('tr');

        rows.forEach(function(row) {
            row.addEventListener('mouseover', function() {
                var buttons = this.querySelectorAll('.modify-button, .remove-button');
                buttons.forEach(function(button) {
                    button.classList.remove('hide-button');
                    button.classList.add('show-button');
                });
            });

            row.addEventListener('mouseout', function() {
                var buttons = this.querySelectorAll('.modify-button, .remove-button');
                buttons.forEach(function(button) {
                    button.classList.remove('show-button');
                    button.classList.add('hide-button');
                });
            });
        });
    </script>
</html>
<%  
    } else {
        session.setAttribute("errorMessage", "User not identified");
            response.sendRedirect("error.jsp");
            response.flushBuffer();
    }
} 
%>