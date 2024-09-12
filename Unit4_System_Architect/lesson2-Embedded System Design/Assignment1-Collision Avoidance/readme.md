# Unit04/Lesson02/Assignment01-collision Avoidance Project
## Design Sequence
1. Case Study
    1.1. Specifications from the client
    Collision avoidance system that stops a **DC Motor** when it is just 50cm or less from the nearest obstacle.
    1.2. Assumptions
    - Ultrasonic sensor never fails.
    - DC motor never fails
2. Method
    We are going use **V Model**
3. Requirements Diagram
![alt text](figures/CA_Requiements.png)
4. System Analysis
    4.1. Use Case Diagram
![alt text](figures/CA_Use_Case.png)
    4.2. Activity Diagram
![alt text](figures/CA_Activity.png)
    4.3. Sequence Diagram
![alt text](figures/CA_Sequence.png)
5. System Design
    5.1. Block Diagram
![alt text](figures/CA_Block.png)
    5.1. State Diagram
    - UltraSonic_interface Block
![alt text](figures/CA_US.png)
    - CA main Algorithm Block
![alt text](figures/CA_Main_Algo.png)
    - DC_Motor Interface Block
![alt text](figures/CA_DC_Mottor.png)
## Implementation
- .c, .h for each block
- State.h to carry each block states, modules connectors 
### Output:
![alt text](figures/CA_code_output.png)
