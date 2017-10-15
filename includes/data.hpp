#ifndef DATA_H
#define DATA_H

// this cube does not have the correct winding order.
// have had to disable face culling.
float cube[] = {
  -0.5f, -0.5f, -0.5f, 
  0.5f, -0.5f, -0.5f,  
  0.5f,  0.5f, -0.5f,  
  0.5f,  0.5f, -0.5f,  
  -0.5f,  0.5f, -0.5f, 
  -0.5f, -0.5f, -0.5f, 

  -0.5f, -0.5f,  0.5f, 
  0.5f, -0.5f,  0.5f,  
  0.5f,  0.5f,  0.5f,  
  0.5f,  0.5f,  0.5f,  
  -0.5f,  0.5f,  0.5f, 
  -0.5f, -0.5f,  0.5f, 

  -0.5f,  0.5f,  0.5f, 
  -0.5f,  0.5f, -0.5f, 
  -0.5f, -0.5f, -0.5f, 
  -0.5f, -0.5f, -0.5f, 
  -0.5f, -0.5f,  0.5f, 
  -0.5f,  0.5f,  0.5f, 

  0.5f,  0.5f,  0.5f,  
  0.5f,  0.5f, -0.5f,  
  0.5f, -0.5f, -0.5f,  
  0.5f, -0.5f, -0.5f,  
  0.5f, -0.5f,  0.5f,  
  0.5f,  0.5f,  0.5f,  

  -0.5f, -0.5f, -0.5f, 
  0.5f, -0.5f, -0.5f,  
  0.5f, -0.5f,  0.5f,  
  0.5f, -0.5f,  0.5f,  
  -0.5f, -0.5f,  0.5f, 
  -0.5f, -0.5f, -0.5f, 

  -0.5f,  0.5f, -0.5f, 
  0.5f,  0.5f, -0.5f,  
  0.5f,  0.5f,  0.5f,  
  0.5f,  0.5f,  0.5f,  
  -0.5f,  0.5f,  0.5f, 
  -0.5f,  0.5f, -0.5f, 
};

#endif
