import os
from fastapi import Depends, FastAPI, Form, HTTPException, Response, UploadFile, File
from sqlalchemy.orm import Session
from fastapi.responses import JSONResponse

from sql_app import crud, models
from sql_app.database import SessionLocal, engine

models.Base.metadata.create_all(bind=engine)

app = FastAPI()

# Dependency
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
        
@app.post("/registerUser")
async def create_user(
    username: str = Form(...),
    password: str = Form(...),
    db: Session = Depends(get_db)
):
    if crud.create_user(db, username, password):
        return JSONResponse(content="true", status_code=201)
    else:
        return JSONResponse(content="false", status_code=500)
    
@app.post("/login")
async def check_user(
    username: str = Form(...),
    password: str = Form(...),
    db: Session = Depends(get_db)
):
    if crud.check_user(db, username, password):
        return JSONResponse(content="true", status_code=200)
    else:
        return JSONResponse(content="false", status_code=403)
    
@app.post("/register")
async def register_image(
    title: str = Form(...), 
    description: str = Form(...), 
    keywords: str = Form(...), 
    author: str = Form(...), 
    creator: str = Form(...), 
    capture: str = Form(...),
    file: UploadFile = File (...),
    db: Session = Depends(get_db)
):
    if crud.create_image(db, title, description, keywords, author, creator, capture, file):
        return JSONResponse(content="true", status_code=201)
    else:
        return JSONResponse(content="false", status_code=500)

@app.post("/modify")
async def modify_image(
    id: str = Form(...),
    title: str = Form(...), 
    description: str = Form(...), 
    keywords: str = Form(...), 
    author: str = Form(...), 
    creator: str = Form(...), 
    capture: str = Form(...),
    db: Session = Depends(get_db)
):
    if crud.modify_image(db, id, title, description, keywords, author, creator, capture):
        return JSONResponse(content="true", status_code=200)
    else:
        return JSONResponse(content="false", status_code=500)

@app.get("/search")
async def search_image(
    title: str = None,
    description: str = None,
    keywords: str = None,
    author: str = None,
    cDate: str = None,
    db: Session = Depends(get_db)
):
    return JSONResponse(content=crud.search_image(db, title, description, keywords, author, cDate), 
                        status_code=200)

@app.post("/delete")
async def delete_image(
    id: int = Form(...), 
    fileName: str = Form(...),
    db: Session = Depends(get_db)
): 
    if crud.delete_image(db, id, fileName): 
        return JSONResponse(content="true", status_code=200)
    else: 
        return JSONResponse(content="false", status_code=500)

@app.get("/list")
async def list_image(
    db: Session = Depends(get_db)
): 
   return crud.getAllImages(db)

@app.get("/download")
async def download_image(
    filename: str = None, 
    db: Session = Depends(get_db)
): 
    try:
        file_path = f"images/{filename}"
        if (not os.path.exists(file_path)): 
            raise HTTPException()

        with open(file_path, "rb") as image_file: 
            image_content = image_file.read()

        return Response(content=image_content, media_type="image/jpeg")

    except Exception: 
        return JSONResponse(content="Error downloading the image", status_code=500)