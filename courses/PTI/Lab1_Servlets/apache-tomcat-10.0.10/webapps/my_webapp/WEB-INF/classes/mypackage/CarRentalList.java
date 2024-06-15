package mypackage;

import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.util.Iterator;

public class CarRentalList extends HttpServlet {

  public void doGet(HttpServletRequest req, HttpServletResponse res)
                    throws ServletException, IOException {
    res.setContentType("text/html");
    PrintWriter out = res.getWriter();

    /* Retrieve data */
    String user = req.getParameter("userid");
    String password = req.getParameter("password");
    
    /* Check identity and print rental list if verified */
    if(user.equals("admin") && password.equals("admin")){
      out.print("<h1>Rental list</h1>");

      JSONParser parser = new JSONParser();
      try (Reader reader = new FileReader("rentals.json")) {
        JSONObject jsonObject = (JSONObject) parser.parse(reader);
        JSONArray rentals = (JSONArray) jsonObject.get("rentals");
        
        int nRentals = 1;
        for (Object obj : rentals) {
          JSONObject rental = (JSONObject) obj;
          out.println("<h3>Rental ID " + nRentals + "</h3>");
          out.println("<b>Engine: </b>" + rental.get("engine") + "<br>");
          out.println("<b>CO2 Rating: </b>" + rental.get("rating") + "<br>");
          out.println("<b>Days: </b>" + rental.get("days") + "<br>");
          out.println("<b>Discount: </b>" + rental.get("disc") + "%<br>");
          out.println("<b>Units: </b>" + rental.get("units") + "<br>");
          out.println("<hr>");
          ++nRentals;
        }

        if(nRentals == 1) out.println("<h2>No rentals registered.</h2>");
      
      } catch (IOException | ParseException e) {
          e.printStackTrace();
          out.println("<h2>No rentals registered.</h2>");
      } 

    } else {
      out.print("<h1>Incorrect password</h1>");
    }
  }

  public void doPost(HttpServletRequest req, HttpServletResponse res)
                    throws ServletException, IOException {
    doGet(req, res);
  }
}
