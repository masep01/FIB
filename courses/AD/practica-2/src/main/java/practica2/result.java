/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/JSP_Servlet/Servlet.java to edit this template
 */
package practica2;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author alumne
 */
@WebServlet(name = "result", urlPatterns = {"/result"})
public class result extends HttpServlet {

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
            
                /* Retrieve the pressed button and the image requested */
                List<String[]> list = (List<String[]>)session.getAttribute("result");
                if(list != null) {
                    int id = Integer.parseInt(request.getParameter("id"));
                    String button = request.getParameter("button");
                    /* Get the image from the list */
                    String[] imageInfo = list.get(id);

                    if(list==null) throw new ClassNotFoundException("Error trying to modify or delete the image");
                    else {
                        session.setAttribute("imageInfo", imageInfo);
                        /* Redirect to modify or delete image */
                        if(button.equals("modify")) response.sendRedirect("modificarImagen.jsp");
                        else response.sendRedirect("eliminarImagen.jsp");
                    }
                } else {
                    session.setAttribute("errorMessage", "Error searching images");
                    response.sendRedirect("error.jsp");
                }
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(buscarImagen.class.getName()).log(Level.SEVERE, null, ex);
                System.err.println(ex.getMessage());
                session.setAttribute("errorMessage", "Error searching images");
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
