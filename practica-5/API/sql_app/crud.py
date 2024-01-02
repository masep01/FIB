import os
from fastapi import UploadFile
from sqlalchemy.orm import Session
from sqlalchemy import or_
from datetime import datetime

from . import models

def create_user(db: Session, username: str, passw: str):
    user_data = models.User(id_usuario=username, password=passw)
    db.add(user_data)
    db.commit()
    db.refresh(user_data)
    return True

def check_user(db: Session, username: str, passw: str):
    result =  db.query(models.User).filter(
        (models.User.id_usuario == username) &
        (models.User.password == passw)).first()
    return result != None

def create_image(db: Session, title: str, description: str, keywords: str, 
                 author: str, username: str, capture_date: str, file: UploadFile):
    try:
        user = db.query(models.User).filter_by(id_usuario=username).scalar() is not None
        if not user: 
            raise Exception

        image_data = models.Image(
        title=title, 
        description=description, 
        keywords=keywords,
        author=author, 
        creator=username, 
        capture_date=capture_date,
        storage_date=datetime.now().strftime("%d-%m-%Y"), 
        filename="temp.jpg")
    
        db.add(image_data)
        db.commit()
        db.refresh(image_data)

        image_data.filename = f"{image_data.id}.jpg"
        db.commit()
        db.refresh(image_data)

        path = f"images/{image_data.filename}"
        file_content = file.file.read()
        with open(path, "wb") as image:
            image.write(file_content)

    except Exception:           
        return False
    finally:
        file.file.close()
    return True

def modify_image(db: Session, id: str, new_title: str, new_description: str, new_keywords: str, 
                 new_author: str, username: str, new_capture_date: str):
    try:
        image = db.query(models.Image).filter_by(id=id).first()
        if image.creator != username:
            raise Exception
        
        if image:
            image.title = new_title
            image.description = new_description
            image.keywords = new_keywords
            image.author = new_author
            image.capture_date = new_capture_date
            db.commit()
        else:  raise Exception

    except Exception:           
        return False
    
    return True

def search_image(db: Session, title: str, description: str, keywords: str, 
                 author: str, capture_date: str):
    try:
        query = db.query(models.Image)
        if not any([title, description, keywords, author, capture_date]):
            return []

        conditions = []
        if title:
            conditions.append(models.Image.title.like(f"%{title}%"))
        if description:
            conditions.append(models.Image.description.like(f"%{description}%"))
        if keywords:
            conditions.append(models.Image.keywords.like(f"%{keywords}%"))
        if author:
            conditions.append(models.Image.author.like(f"%{author}%"))
        if capture_date:
            conditions.append(models.Image.capture_date.like(f"%{capture_date}%"))

        if conditions:
            query = query.filter(or_(*conditions))

        result = query.all()
        
        formatted_result = queryToJSON(result)
        
        return formatted_result

    except Exception:           
        return []
    
def delete_image(db: Session, id: int, fileName: str):
    try: 
        db.query(models.Image).filter(models.Image.id == id).delete()
        db.commit() 

        path = f"images/{fileName}"
        os.remove(path)

    except Exception: 
        return {"message: There was an error deleting the file"}

    return True

def getAllImages(db: Session): 
        images = db.query(models.Image).all()
        formatted_result = queryToJSON(images)
        return formatted_result

def queryToJSON(content): 
    try:
        formatted_result = []
        for row in content:
            data = [str(getattr(row, field)) for field in row.__table__.columns.keys()]
            formatted_result.append(data)

        return formatted_result
    except Exception: 
        return []
