
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Geometry>
#include<sophus/so3.h>
#include<iostream>

using namespace std;

int main()
{
    // the current Pose of Rotation with  R&q
    Eigen::Matrix3d current_R = Eigen::AngleAxisd(M_PI/2,  Eigen::Vector3d(1.0, 2.0, 3.0)).toRotationMatrix();  


    Eigen::Matrix3d test_R = Eigen::AngleAxisd(M_PI/2,  Eigen::Vector3d(3.0, 2.0, 1.0)).toRotationMatrix(); 
    Eigen::Vector3d test_P(1,2,3);

    Eigen::Matrix3d  result_R_1,result_R_2;
    Eigen::Vector3d test_p_1 = (current_R.inverse())*test_P;
    Eigen::Vector3d test_p_2 = (current_R.transpose())*test_P;

    cout << "test1 \r\n" << test_p_1 << endl;
    cout << "test2 \r\n" << test_p_2 << endl;
    

     


    Sophus::SO3   current_SO3_R(current_R);
    cout << "\r\n the current Pose of R: \r \n" << current_R <<endl;

    Eigen::Quaterniond current_q(current_R);
    cout << "\r\n the current Pose of q:[x,y,z,w] \r \n" << current_q.coeffs().transpose()  <<endl;


    // the update rotatoin w
    Eigen::Vector3d  update_w = Eigen::Vector3d(0.01, 0.02, 0.03);
    cout << "\r\n the update Pose of rotate vector \r \n" << update_w.transpose() << endl;
    
    //Type one:
    // R <--- R*exp^(w^hat)
    Sophus::SO3 updated_R_from_rotateMatrix = current_SO3_R * Sophus::SO3::exp(update_w);
    cout << "\r\n the updated_pose_from_rotateMatrix:  R <--- R*exp^(w^hat) \r\n"
             << updated_R_from_rotateMatrix.matrix()<<endl;
             

    //Type two:
    // q <--- q*[1, 1/2w]^T
    Eigen::Quaterniond update_q;
    update_q.w() = 1;
    update_q.x() = 1/2*update_w.x();
    update_q.y() = 1/2*update_w.y();
    update_q.z() = 1/2*update_w.z();

    update_q = update_q.normalized();
    Eigen::Quaterniond updated_R_from_quaternion = current_q * update_q;
    updated_R_from_quaternion = updated_R_from_quaternion.normalized();
    cout << "\r\n the updated_pose_from_Quaternion: " << "q <--- q*[1, 1/2w]^T \r\n" 
            << updated_R_from_quaternion.matrix() << endl;
    

    return 0;
}