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
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import java.util.List;

/**
 *
 * @author alumne
 */
@WebServlet(name = "buscarImagen", urlPatterns = {"/buscarImagen"})
public class buscarImagen extends HttpServlet {

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
                
                /* Retrieve data from form and process it */
                String title = request.getParameter("title");
                String description = request.getParameter("desc");
                String keywords = request.getParameter("keywords"); 
                String author = request.getParameter("author");
                String cDate = request.getParameter("creationDate"); 
                
                if(title == null || description == null || keywords == null || author == null || cDate == null)
                {
                    session.setAttribute("errorMessage", "Error searching images");
                    response.sendRedirect("error.jsp");
                    
                } else {
                    /* Prepare data to send */
                    String sUrl = "http://localhost:8080/WS-Backend/resources/jakartaee9/search";
                    sUrl += "?title=" + URLEncoder.encode(title, "UTF-8");
                    sUrl += "&description=" + URLEncoder.encode(description, "UTF-8");
                    sUrl += "&keywords=" + URLEncoder.encode(keywords, "UTF-8");
                    sUrl += "&author=" + URLEncoder.encode(author, "UTF-8");
                    sUrl += "&cDate=" + URLEncoder.encode(cDate, "UTF-8");

                    /* Prepare POST request */
                    URL url = new URL(sUrl);
                    HttpURLConnection con = (HttpURLConnection) url.openConnection();
                    con.setRequestMethod("GET");
                    con.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
                    con.setDoOutput(true);

                    /* Read answer */
                    StringBuilder info = new StringBuilder();
                    try (BufferedReader reader = new BufferedReader(new InputStreamReader(con.getInputStream()))) {
                        String line;
                        while ((line = reader.readLine()) != null) {
                            info.append(line);
                        }
                    }

                    String result = info.toString();
                    if(result!=null){
                        Gson gson = new Gson();
                        List<String[]> list = gson.fromJson(result, new TypeToken<List<String[]>>(){}.getType());
                        session.setAttribute("result", list);
                        response.sendRedirect("result.jsp");
                    }
                    else throw new ClassNotFoundException("Error searching images");
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
