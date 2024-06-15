from sqlalchemy import Column, ForeignKey, Integer, String

from .database import Base

class User(Base):
    __tablename__ = "users"

    id_usuario = Column(String, primary_key=True, index=True)
    password = Column(String, index=True)
    
class Image(Base):
    __tablename__ = "images"

    id = Column(Integer, primary_key=True, index=True, autoincrement=True)
    title = Column(String, index=True)
    description = Column(String, index=True)
    keywords = Column(String, index=True)
    author = Column(String, index=True)
    creator = Column(String, ForeignKey("users.id_usuario"))
    capture_date = Column(String, index=True)
    storage_date = Column(String, index=True)
    filename = Column(String, index=True)

