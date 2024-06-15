package test.practica_3.resources;

import database.*;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.FormParam;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.MediaType;
import jakarta.ws.rs.core.Response;
import java.sql.Connection;
import java.time.LocalDate;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 *
 * @author 
 */
@Path("jakartaee9")
public class JakartaEE91Resource {
    
    /**
     * OPERACIONES DEL SERVICIO REST
    */
    
    /**
     * POST method to login in the application
     *
     * @param username
     * @param password
     * @return
     */
    @Path("login")
    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Produces(MediaType.APPLICATION_JSON)
    public Response login(@FormParam("username") String username, @FormParam("password") String password) {
        try {
            Connection connection = ManageDB.open_connection();
            boolean user_exists = OperateDB.check_user(username, password, connection);
            ManageDB.close_connection(connection);
            return Response.ok(user_exists).build();
            
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.serverError().build();
        }   
    }
    
    /**
    * POST method to register a new image – File is not uploaded
    * @param title
    * @param description
    * @param keywords
    * @param author
    * @param creator
    * @param capt_date
    * @return
    */
    @Path("register")
    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Produces(MediaType.APPLICATION_JSON)
    public Response registerImage (@FormParam("title") String title,
    @FormParam("description") String description,
    @FormParam("keywords") String keywords,
    @FormParam("author") String author,
    @FormParam("creator") String creator,
    @FormParam("capture") String capt_date){
        boolean success = false;
        try {
            Connection connection = ManageDB.open_connection();
            if (title != null && description != null && keywords != null &&
                author != null && creator != null && capt_date != null) {
                
                String sDate = LocalDate.now().toString();
                success = OperateDB.insert_image(title, description, 
                    keywords, author, creator, capt_date, sDate, connection);
            }
            ManageDB.close_connection(connection);  
            return Response.ok(success).build();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.ok(success).build();
        }
    }
    
    /**
    * POST method to modify an existing image
    * @param id
    * @param title
    * @param description
    * @param keywords
    * @param author
    * @param creator, used for checking image ownership
    * @param capt_date
    * @return
    */
    @Path("modify")
    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Produces(MediaType.APPLICATION_JSON)
    public Response modifyImage (@FormParam("id") String id,
    @FormParam("title") String title,
    @FormParam("description") String description,
    @FormParam("keywords") String keywords,
    @FormParam("author") String author,
    @FormParam("creator") String creator,
    @FormParam("capture") String capt_date){
        boolean success = false;
        try {
            Connection connection = ManageDB.open_connection();
            if (id!= null && title != null && description != null && keywords != null &&
                author != null && creator != null && capt_date != null) {
                
                success = OperateDB.update_imageInfo(id, title, 
                            description, keywords, author, capt_date, connection);
            }
            ManageDB.close_connection(connection);     
            return Response.ok(success).build();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.ok(success).build();
        }
    }
    
    /**
    * GET method to search images by keyword
     * @param title
     * @param keywords
     * @param description
     * @param author
     * @param cDate
    * @return
    */
    @Path("search")
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response searchByKeywords(@QueryParam("title") String title,
            @QueryParam("description") String description,
            @QueryParam("keywords") String keywords,
            @QueryParam("author") String author,
            @QueryParam("cDate") String cDate) {
        try {
            Connection connection = ManageDB.open_connection();
            String json = null;
            if (title != null && description != null && keywords != null &&
                author != null && cDate != null) {
                
                List<String[]> result = OperateDB.search_images(title, description, keywords, author, cDate, connection);
                json = listToJSON(result);
            }
            ManageDB.close_connection(connection);     
            return Response.ok(json).build();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.ok(null).build();
        }
    }
    
    /**
    * POST method to delete an existing image
    * @param id
    * @return
    */
    @Path("delete")
    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Produces(MediaType.APPLICATION_JSON)
    public Response deleteImage (@FormParam("id") String id) {
        boolean success = false;
        try {
            Connection connection = ManageDB.open_connection();
            if (id!= null) success = OperateDB.erase_image_DB(id, connection);
            ManageDB.close_connection(connection);     
            return Response.ok(success).build();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.ok(success).build();
        }
    }
    
    /**
    * GET method to list all images 
    * @return
    */
    @Path("list")
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response listAllImages() {
        String json = null; 
        List<String[]> result = OperateDB.getAllImages();
        json = listToJSON(result);   
        return Response.ok(json).build();
    }
    
    /**
    * POST method to register a new user
    * @param username
    * @param password
    * @return
    */
    @Path("registerUser")
    @POST
    @Consumes(MediaType.APPLICATION_FORM_URLENCODED)
    @Produces(MediaType.APPLICATION_JSON)
    public Response registerUser (@FormParam("username") String username,
    @FormParam("password") String password){
        int status = -1; 
        try {
            Connection connection = ManageDB.open_connection();
            if (username != null && password != null) status = OperateDB.register_user(username, password, connection);
            ManageDB.close_connection(connection);     
            return Response.ok(status).build();
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(JakartaEE91Resource.class.getName()).log(Level.SEVERE, null, ex);
            return Response.ok(status).build();
        }
    }
    
    public static String listToJSON(List<String[]> list){
        ObjectMapper objectMapper = new ObjectMapper();
        try {
            return objectMapper.writeValueAsString(list);
        } catch (Exception e) {
            e.printStackTrace();
            return "Error al convertir a JSON";
        }
    }
}