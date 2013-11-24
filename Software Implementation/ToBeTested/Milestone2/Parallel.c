/**
 * Makes the golf cart drive parallel to the wall
 * front - side front sensor
 * back  - side back sensor
 */
 void Parallel (int front, int back)
 {
 	SetSteeringAngle(AngleToSideWall(front, back));
 }