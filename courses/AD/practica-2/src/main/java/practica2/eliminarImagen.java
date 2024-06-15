package practica2;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */

import database.ManageDB;
import database.OperateDB;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.sql.Connection;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author alumne
 */
@WebServlet(urlPatterns = {"/eliminarImagen"})
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
                
                    /* Open connection */
                    Connection connection = ManageDB.open_connection();

                    /* Retrieve data from the session, and erase the session object */        
                    String id = iInfo[0]; 
                    String fileName = iInfo[6]; 

                    /* Delete the data from the DB*/ 
                    boolean success = OperateDB.erase_image_DB(id, connection);
                    /* Delete the data from the server*/ 
                    if (success) OperateDB.erase_image_server(fileName); 
                    session.removeAttribute("imageInfo"); 

                    /* Close connection */
                     ManageDB.close_connection(connection);

                    if (!success) {
                        session.setAttribute("errorMessage", "An error occurred while deleting the photo");
                        response.sendRedirect("error.jsp"); 
                    }

                    else {
                        session.setAttribute("successMessage", "Image deleted correctly");
                        response.sendRedirect("success.jsp"); 
                    }
                }

            } catch (ClassNotFoundException ex) {
                Logger.getLogger(eliminarImagen.class.getName()).log(Level.SEVERE, null, ex);
                System.err.println(ex.getMessage());
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