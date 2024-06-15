/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package practica2;

import database.ManageDB;
import database.OperateDB;
import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.MultipartConfig;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import jakarta.servlet.http.Part;
import java.sql.Connection;
import java.time.LocalDate;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author alumne
 */
@WebServlet(name = "registrarImagen", urlPatterns = {"/registrarImagen"})
@MultipartConfig
public class registrarImagen extends HttpServlet {

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
        if(session == null || request.getContentType()==null) 
        {
            session = request.getSession(true);
            session.setAttribute("errorMessage", "Invalid session");
            response.sendRedirect("error.jsp"); 
            
        } else {
            try (PrintWriter out = response.getWriter()) {
                /* Open connection */
                Connection connection = ManageDB.open_connection();

                /* Retrieve data from form and process it */
                String title = request.getParameter("title");
                String description = request.getParameter("desc");
                String keywords = request.getParameter("keywords"); 
                String author = request.getParameter("author");
                String creator = session.getAttribute("username").toString();
                String cDate = request.getParameter("creationDate");
                String sDate = LocalDate.now().toString();
                Part filePart = request.getPart("file");

                if (title != null && description != null && keywords != null &&
                    author != null && creator != null && cDate != null && filePart != null) {

                    /* Insert all data in DB and upload the file */
                    boolean success = OperateDB.insert_image(title, description, 
                            keywords, author, creator, cDate, sDate, filePart, connection);

                    if (success) {
                        session.setAttribute("successMessage", "Image successfully uploaded");
                        response.sendRedirect("success.jsp");
                    } else {
                        throw new ClassNotFoundException("Error trying to upload a new image");
                    }

                    /* Close connection */
                    ManageDB.close_connection(connection);
                } else {
                    session.setAttribute("errorMessage", "Error: All fields are required");
                    response.sendRedirect("error.jsp");
                }
            
            } catch (IllegalStateException | ServletException | ClassNotFoundException ex) {
                Logger.getLogger(registrarImagen.class.getName()).log(Level.SEVERE, null, ex);
                System.err.println(ex.getMessage());
                session.setAttribute("errorMessage", "Error trying to upload a new image");
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
