/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package practica3;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;

/**
 *
 * @author alumne
 */
@WebServlet(name = "register", urlPatterns = {"/register"})
public class register extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            
            /* Creates a temporal session to store the success/error messages */  
            HttpSession session = request.getSession(true);
            
            /* Retrieve data from form and process it */
            String username = request.getParameter("uname");
            String password = request.getParameter("pw");
            
            /* Prepare data to send */
            StringBuilder postData = new StringBuilder();
            postData.append("username=");
            postData.append(URLEncoder.encode(username, "UTF-8"));
            postData.append("&password=");
            postData.append(URLEncoder.encode(password, "UTF-8"));
            
            byte[] postBytes = postData.toString().getBytes("UTF-8");

            /* Prepare POST request */
            URL url = new URL("http://localhost:8080/WS-Backend/resources/jakartaee9/registerUser");
            HttpURLConnection con = (HttpURLConnection) url.openConnection();
            con.setRequestMethod("POST");
            con.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
            con.setRequestProperty("Content-Length", String.valueOf(postBytes.length));
            con.setDoOutput(true); 
            con.getOutputStream().write(postBytes);
            
            /* Read answer */
            StringBuilder info = new StringBuilder();
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(con.getInputStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    info.append(line);
                }
            }
            
            int new_user = Integer.parseInt(info.toString()); 
                    
            /* Treat the result of the process */
            switch (new_user) {
                case 0:
                    session.setAttribute("errorMessage", "User already exists");
                    response.sendRedirect("error.jsp");
                    break;
                case -1: 
                    session.setAttribute("errorMessage", "An error occurred in the register process");
                    response.sendRedirect("error.jsp");
                    break;
                default:
                    session.setAttribute("successMessage", "Welcome to our family "+username+"!");
                    response.sendRedirect("registerSuccess.jsp");
                    break;
            }
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}