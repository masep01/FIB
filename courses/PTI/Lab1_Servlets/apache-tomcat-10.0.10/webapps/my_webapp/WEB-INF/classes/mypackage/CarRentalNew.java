package mypackage;

import java.io.*;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import org.json.simple.*;
import java.lang.String.*;

public class CarRentalNew extends HttpServlet {

  int cont = 0;
  JSONObject mainJsonObject = new JSONObject();

  public void doGet(HttpServletRequest req, HttpServletResponse res)
                    throws ServletException, IOException {
    res.setContentType("text/html");
    PrintWriter out = res.getWriter();
    
    /* Get form parameters */
    String carType = req.getParameter("sub_model_vehicle");
    String co2 = req.getParameter("co2_rating");
    String days = req.getParameter("dies_lloguer");
    String vehicles = req.getParameter("num_vehicles");
    String discount = req.getParameter("descompte");               
    if ( carType == null || carType.isEmpty() ||
    co2 == null || co2.isEmpty() || days == null || days.isEmpty() ||
    vehicles == null || vehicles.isEmpty() || discount == null || discount.isEmpty()) {
      out.println("Please fill the empty fields.");
      return;
    }


    /* Check if rentals.json exists. Create it otherwise */
    File file = new File("rentals.json");
    file.createNewFile();
    cont ++;

    /* Write form parameters to rentals.json */

    JSONObject jsonObject = new JSONObject();
    jsonObject.put("rating", co2);
    jsonObject.put("engine", carType);
    jsonObject.put("days", days);
    jsonObject.put("units", vehicles);
    jsonObject.put("disc", discount);

    JSONArray array = new JSONArray();
    if(cont>1) array = (JSONArray) mainJsonObject.get("rentals");

    array.add(jsonObject);
    mainJsonObject.put("rentals", array);

    try (FileWriter fileWriter = new FileWriter("rentals.json")) {
      fileWriter.write(mainJsonObject.toJSONString());
      fileWriter.flush();
    } catch (IOException e) {
      e.printStackTrace();
    }

    /* Print form parameters */
    out.println("<html>");
    out.println("<head>");
    out.println("<title>New Rental</title>");
    out.println("</head>");
    out.println("<body>");
    out.println("<h1>New Rental</h1>");
    out.println("<br>C02 Rating: " + co2);
    out.println("<br>Engine: " + carType);
    out.println("<br>Number of days: " + days);
    out.println("<br>Number of units: " + vehicles);
    out.println("<br>Discount: " + discount);
    out.println("</body>");
    out.println("</html>");
  }

  public void doPost(HttpServletRequest req, HttpServletResponse res)
                    throws ServletException, IOException {
    doGet(req, res);
  }
  
}
