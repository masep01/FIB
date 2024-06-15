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
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author alumne
 */
@WebServlet(name = "eliminarImagen", urlPatterns = {"/eliminarImagen"})
public class eliminarImagen extends HttpServlet {

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
        
        /* Get the active session to retrieve the data */ 
        HttpSession session = request.getSession(false);
        
        if(session == null) 
        {
            session = request.getSession(true);
            session.setAttribute("errorMessage", "Invalid session");
            response.sendRedirect("error.jsp"); 
            
        } else {
            
            try (PrintWriter out = response.getWriter()) {
                
                /* Get the session attrbute */ 
                String[] iInfo = (String[])session.getAttribute("imageInfo"); 
                
                if (iInfo == null) {
                    session.setAttribute("errorMessage", "Invalid session");
                    response.sendRedirect("error.jsp"); 
                }
                
                else {
                    
                     /* Retrieve data from the session */        
                    String id = iInfo[0]; 
                
                     /* Prepare data to send */
                    StringBuilder postData = new StringBuilder();
                    postData.append("id=");
                    postData.append(URLEncoder.encode(id, "UTF-8"));
                    
                    byte[] postBytes = postData.toString().getBytes("UTF-8");
            

                    /* Prepare POST request */
                    URL url = new URL("http://localhost:8080/WS-Backend/resources/jakartaee9/delete");
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

                    boolean success = info.toString().equals("true");

                    if (success) {
                        session.setAttribute("successMessage", "Image successfully deleted");
                        response.sendRedirect("success.jsp");

                    } else throw new ClassNotFoundException("Error trying to delete a new image");
                }
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(buscarImagen.class.getName()).log(Level.SEVERE, null, ex);
                System.err.println(ex.getMessage());
                session.setAttribute("errorMessage", "Error deleting the image");
                response.sendRedirect("error.jsp");
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