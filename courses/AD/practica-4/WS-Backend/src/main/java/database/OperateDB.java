/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package database;

import database.ManageDB;
import jakarta.servlet.http.Part;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 *
 * @author alumne
 */
public class OperateDB {
    
    /* Returns true if the user identified by {username, password} exists in DB, false otherwise. */
    public static boolean check_user(String username, String password, Connection connection){
        try{    
            String query;
            PreparedStatement statement;
        
            query = "select * from usuarios where id_usuario=? and password=?";
            statement = connection.prepareStatement(query);
            statement.setString(1, username);
            statement.setString(2, password);
            
            ResultSet rs = statement.executeQuery();
        
            return rs.next();
            
        } catch (SQLException e){
            System.err.println(e.getMessage());
            return false;
        }   
    }
    
    /* Inserts an image in the DB. Returns true if completed successfully, false otherwise. */
    public static boolean insert_image(String title, String description, String keywords, 
            String author, String creator, String cDate,String sDate, InputStream input, 
            Connection connection){ 
        String filename = null;
        try {
           
            String original = "tempName.jpg";      // Retrieve filename
            
            /* SQL query */
            String query;
            PreparedStatement statement;

            query = "INSERT INTO IMAGE (TITLE, DESCRIPTION, KEYWORDS, AUTHOR, CREATOR, CAPTURE_DATE, STORAGE_DATE, FILENAME)"
                        + "VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
            statement = connection.prepareStatement(query);            
            statement.setString(1, title);
            statement.setString(2, description);
            statement.setString(3, keywords);
            statement.setString(4, author);
            statement.setString(5, creator);
            statement.setString(6, cDate);
            statement.setString(7, sDate);
            statement.setString(8, original); 
            statement.executeUpdate();
            
             /* Upload file into Server */
            File uploads = new File("/var/webapp/images");                                          // Path to uploads storage      

            int lastId = OperateDB.getLastID(connection);
            if(lastId==-1) throw new IOException("Error retrieving index");
            
            String extension = "";
            int lastDotIndex = original.lastIndexOf(".");
            if (lastDotIndex >= 0) {
                extension = original.substring(lastDotIndex);
            }
            
            filename = Integer.toString(lastId) + extension;
            
            File file = new File(uploads, filename);                                            // Path of new file (uploads/filename)  
            
            // Get the file from the filepart and copy it into the destination path  
            Files.copy(input, file.toPath(), StandardCopyOption.REPLACE_EXISTING);
            
            query = "UPDATE IMAGE SET FILENAME=? WHERE ID=?";
            statement = connection.prepareStatement(query);            
            statement.setString(1, filename);
            statement.setString(2, Integer.toString(lastId));
            statement.executeUpdate();
            return true;
            
        } catch (SQLException | IOException ex) {
            if(filename!=null) OperateDB.erase_image_server(filename);
            
            System.err.println(ex.getMessage());
            return false;
        } 
    }
    
    /* Updates fields of the image identifed by 'id' */
    public static boolean update_imageInfo(String id, String title, String description, 
            String keywords, String author, String cDate, Connection connection){
        try{
            /* SQL query */
            String query;
            PreparedStatement statement;

            query = "UPDATE IMAGE "
                    + "SET TITLE =?, DESCRIPTION = ?, KEYWORDS = ?, AUTHOR = ?, CAPTURE_DATE = ?"
                    + "WHERE ID=?";
            statement = connection.prepareStatement(query);            
            statement.setString(1, title);
            statement.setString(2, description);
            statement.setString(3, keywords);
            statement.setString(4, author);
            statement.setString(5, cDate);
            statement.setString(6, id); 
            statement.executeUpdate();
            return true;
            
        } catch(SQLException ex){
            System.err.println(ex.getMessage());
            return false;
        }
    }
    
    /* Returns the ID of the last image in the DB, -1 if there was an error */
    public static int getLastID(Connection connection){
        try{ 
            /* SQL query */
            String query;
            PreparedStatement statement;

            query = "SELECT IDENTITY_VAL_LOCAL() as lastID FROM IMAGE";
            statement = connection.prepareStatement(query);            
            ResultSet rs = statement.executeQuery();
            if(rs.next()){
                return rs.getInt("lastID");
                
            } else return -1;
            
        }catch(SQLException ex){
            System.err.println(ex.getMessage());
            return -1;
        }
    }
    
    /* Returns a list of arrays containing the information of images that match the search criteria*/
    public static List<String[]> search_images(String title, String description, 
            String keywords, String author, String cDate, Connection connection){
        try{
            /* SQL query */
            String query;
            PreparedStatement statement;
            
            /* Construct the query with non-empty fields */
            query = "SELECT * FROM IMAGE WHERE 1=1";       
            List<Object> list = new ArrayList<Object>();
            if(!title.isBlank()){
                query += " AND TITLE LIKE ?";
                list.add("%" + title + "%");
            }
            if(!description.isBlank()){
                query += " AND DESCRIPTION LIKE ?";
                list.add( "%" + description + "%");
            }
            if(!keywords.isBlank()){
                query += " AND KEYWORDS LIKE ?";
                list.add("%" + keywords + "%");
            }
            if(!author.isBlank()){
                query += " AND AUTHOR LIKE ?";
                list.add("%" + author + "%");
            }
            if(!cDate.isBlank()){
                query += " AND CAPTURE_DATE LIKE ?";
                list.add("%" + cDate + "%");
            }
            
            statement = connection.prepareStatement(query);
            for(int i = 0; i < list.size(); ++i){
                statement.setObject(i+1, list.get(i));
            }
            
            ResultSet rs = statement.executeQuery();
            
            /* Return a Set of all data about the requested image */
            List<String[]> result = new ArrayList<>();     
            while(rs.next()){
                String[] data = new String[9];
                for(int i = 0; i < 9; ++i){
                    data[i] = rs.getString(i+1);
                }
                result.add(data);
            }
            return result;
            
        } catch(SQLException ex){
            System.err.println(ex.getMessage());
            return null;
        }
    }
    
    /* Returns all existing images in the DB  */
    public static List<String[]> getAllImages() {
        try {
         /* Open connection */
         Connection connection = ManageDB.open_connection();
         
         List<String[]> imageList = new ArrayList<>();
           
         /* SQL query */
           String query;
           PreparedStatement statement;
           
           query = "SELECT * FROM IMAGE";
           statement = connection.prepareStatement(query);
           ResultSet rs = statement.executeQuery();
           
           
           while (rs.next()) {
             String[] imageInfo = new String[9];
             for (int i = 0; i < 9; ++i) { imageInfo[i] = rs.getString(i+1); }
             imageList.add(imageInfo);
           }
           
           /* Close connection */
           ManageDB.close_connection(connection);
           
           return imageList;
           
        } catch (SQLException | ClassNotFoundException ex) {
            System.err.println(ex.getMessage());
            Logger.getLogger(OperateDB.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
      
    /* Erase the image info from the DataBase */
    public static boolean erase_image_DB(String id, Connection connection) {
        try {
           /* SQL query */
           String query;
           PreparedStatement statement;
           
           query = "DELETE FROM IMAGE WHERE ID=?";
           statement = connection.prepareStatement(query);
           statement.setString(1, id);
           int rowsDeleted = statement.executeUpdate();
           return rowsDeleted != 0;
           
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
            return false;
        }
    }
   
   
    /* Erase the image from the server */
    public static void erase_image_server(String fileName) {
       
          /* Erase the file from the Server */
           File file = new File("/var/webapp/images/"+fileName+"");
           file.delete();
    }
    
    /* Inserts a new user in the DB. Returns 1 if insertion was completed succesfully, 0 if the user already exits, -1 in case of error. */
    public static int register_user(String username, String password, Connection connection){
        try{    
            String query;
            PreparedStatement statement;
       
            query = "insert into usuarios(id_usuario, password) values (?,?)";
            statement = connection.prepareStatement(query);
            statement.setString(1, username);
            statement.setString(2, password);
           
            statement.executeUpdate();
            return 1;
           
        } catch (SQLException e){
            System.err.println(e.getMessage());
            if(e.getErrorCode() == 30000) return 0;
            return -1;
        }  
    }

}
