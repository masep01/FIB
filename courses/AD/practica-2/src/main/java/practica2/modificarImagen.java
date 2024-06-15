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
@WebServlet(name = "modificarImagen",urlPatterns = {"/modificarImagen"})
public class modificarImagen extends HttpServlet {

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
                /* Open connection */
                Connection connection = ManageDB.open_connection();

                /* Retrieve data from form and process it */
                String[] imageInfo = (String[])session.getAttribute("imageInfo");
                if(imageInfo == null) {
                    session.setAttribute("errorMessage", "Error trying to update image values");
                    response.sendRedirect("error.jsp");       
                } else {
                    String id = imageInfo[0];
                    String new_title = request.getParameter("new_title");
                    String new_description = request.getParameter("new_desc");
                    String new_keywords = request.getParameter("new_keywords"); 
                    String new_author = request.getParameter("new_author");
                    String new_cDate = request.getParameter("new_cDate");

                    /* Update values */
                    boolean success = OperateDB.update_imageInfo(id, new_title, 
                            new_description, new_keywords, new_author, new_cDate, connection);

                    if(!success){
                        session.setAttribute("errorMessage", "Error trying to update image values");
                        response.sendRedirect("error.jsp");
                    }
                    else {
                        session.setAttribute("successMessage", "Image successfully modified");
                        response.sendRedirect("success.jsp");
                    }

                    /* Close connection */
                    ManageDB.close_connection(connection);
                }
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(modificarImagen.class.getName()).log(Level.SEVERE, null, ex);
                System.err.println(ex.getMessage());
                session.setAttribute("errorMessage", "Error trying to update image values");
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
