#include <ros/ros.h>
#include <ros/console.h>
#include <nav_msgs/Path.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>

main (int argc, char **argv)
{
    ros::init (argc, argv, "showpath");

    ros::NodeHandle ph;
    ros::Publisher path_pub = ph.advertise<nav_msgs::Path>("trajectory",1, true);

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    nav_msgs::Path path;
    //nav_msgs::Path path;
    path.header.stamp=current_time;
    path.header.frame_id="camera_init";

    double pose[][3]={{-1.28, 0.17, 0.2},
    {-1.272702785430058, 0.7455575961636568, 0.2579859198041016},
    {-1.2653565962656874, 1.3085940210182636, 0.31234771962044694},
    {-1.257961432506887, 1.85910927456382, 0.3630853994490358},
    {-1.2505172941536578, 2.397103356800327, 0.4101989592898684},
    {-1.2430241812059994, 2.9225762677277833, 0.4536883991429446},
    {-1.2354820936639117, 3.435528007346189, 0.49355371900826445},
    {-1.227891031527395, 3.9359585756555453, 0.529794918885828},
    {-1.2202509947964493, 4.423867972655851, 0.5624119987756351},
    {-1.2125619834710741, 4.899256198347108, 0.5914049586776859},
    {-1.2048239975512705, 5.3621232527293134, 0.6167737985919804},
    {-1.197037037037037, 5.812469135802469, 0.6385185185185185},
    {-1.1892011019283746, 6.250293847566574, 0.6566391184573003},
    {-1.1813161922252833, 6.675597388021631, 0.6711355984083257},
    {-1.1733823079277623, 7.088379757167635, 0.6820079583715947},
    {-1.1653994490358126, 7.488640955004592, 0.6892561983471074},
    {-1.1573676155494337, 7.876380981532497, 0.6928803183348637},
    {-1.1492868074686255, 8.251599836751351, 0.6928803183348637},
    {-1.1411570247933884, 8.614297520661157, 0.6892561983471074},
    {-1.1329782675237219, 8.964474033261912, 0.6820079583715947},
    {-1.1247505356596266, 9.302129374553617, 0.6711355984083257},
    {-1.116473829201102, 9.627263544536273, 0.6566391184573003},
    {-1.108148148148148, 9.939876543209877, 0.6385185185185185},
    {-1.0997734925007652, 10.23996837057443, 0.6167737985919804},
    {-1.091349862258953, 10.527539026629935, 0.5914049586776858},
    {-1.082741046831956, 10.802603305785125, 0.5625630037751249},
    {-1.0709504132231407, 11.06548668503214, 0.533570043873074},
    {-1.0547520661157026, 11.316322314049588, 0.5057851239669422},
    {-1.0341460055096419, 11.555110192837466, 0.4792082440567289},
    {-1.0091322314049587, 11.781850321395776, 0.4538394041424344},
    {-0.9797107438016529, 11.996542699724516, 0.42967860422405874},
    {-0.9458815426997246, 12.199187327823692, 0.40672584430160186},
    {-0.9076446280991733, 12.389784205693298, 0.3849811243750637},
    {-0.865, 12.568333333333333, 0.3644444444444445},
    {-0.8179476584022038, 12.734834710743803, 0.34511580450974394},
    {-0.766487603305785, 12.8892883379247, 0.3269952045709621},
    {-0.7106198347107437, 13.031694214876032, 0.31008264462809915},
    {-0.6503443526170797, 13.162052341597796, 0.294378124681155},
    {-0.5856611570247936, 13.28036271808999, 0.2798816447301296},
    {-0.5165702479338843, 13.386625344352616, 0.26659320477502296},
    {-0.4430716253443528, 13.480840220385675, 0.25451280481583516},
    {-0.3651652892561983, 13.563007346189163, 0.24364044485256606},
    {-0.28285123966942133, 13.633126721763086, 0.2339761248852158},
    {-0.1961294765840218, 13.691198347107438, 0.2255198449137843},
    {-0.10500000000000032, 13.737222222222222, 0.21827160493827166},
    {-0.009462809917355597, 13.771198347107438, 0.2122314049586777},
    {0.09048209366391169, 13.793126721763086, 0.20739924497500256},
    {0.19483471074380165, 13.803007346189164, 0.2037751249872462},
    {0.3035950413223142, 13.800840220385673, 0.20135904499540863},
    {0.4167630853994494, 13.786625344352617, 0.20015100499948985},
    {0.5331491684521991, 13.7607157432915, 0.2},
    {0.645615243342516, 13.725229568411384, 0.2},
    {0.7529716355473934, 13.680519844913784, 0.19999999999999998},
    {0.85521834506683, 13.626586572798695, 0.20000000000000004},
    {0.9523553719008261, 13.563429752066115, 0.19999999999999998},
    {1.0443827160493828, 13.491049382716048, 0.20000000000000004},
    {1.1313003775124986, 13.409445464748496, 0.20000000000000004},
    {1.2131083562901748, 13.318617998163452, 0.2},
    {1.2898066523824099, 13.21856698296092, 0.19999999999999998},
    {1.3613952657892048, 13.109292419140903, 0.2},
    {1.4278741965105601, 12.990794306703396, 0.19999999999999998},
    {1.4892434445464746, 12.863072645648401, 0.2},
    {1.545503009896949, 12.72612743597592, 0.2},
    {1.5966528925619832, 12.579958677685951, 0.2},
    {1.6426930925415775, 12.424566370778491, 0.19999999999999998},
    {1.683623609835731, 12.259950515253545, 0.2},
    {1.7194444444444443, 12.086111111111112, 0.2},
    {1.7501555963677173, 11.903048158351188, 0.19999999999999998},
    {1.7757570656055504, 11.710761656973778, 0.2},
    {1.7962488521579432, 11.509251606978879, 0.2},
    {1.8116309560248955, 11.298518008366493, 0.2},
    {1.8219033772064073, 11.07856086113662, 0.2},
    {1.8270661157024795, 10.849380165289254, 0.2},
    {1.827119171513111, 10.610975920824405, 0.2},
    {1.8220625446383019, 10.363348127742064, 0.2},
    {1.8082093663911845, 10.11228650137741, 0.19999999999999998},
    {1.7765472910927458, 9.87194367921641, 0.2},
    {1.7266666666666666, 9.642962962962962, 0.19999999999999998},
    {1.6585674931129477, 9.42534435261708, 0.19999999999999998},
    {1.5722497704315883, 9.219087848178756, 0.2},
    {1.4677134986225895, 9.024193449647996, 0.2},
    {1.3449586776859497, 8.840661157024792, 0.19999999999999998},
    {1.203985307621671, 8.668490970309152, 0.2},
    {1.044793388429753, 8.507682889501071, 0.2},
    {0.8673829201101925, 8.35823691460055, 0.2},
    {0.6717539026629941, 8.22015304560759, 0.2},
    {0.45790633608815345, 8.093431282522191, 0.2},
    {0.22584022038567486, 7.978071625344352, 0.2},
    {-0.02444444444444316, 7.874074074074073, 0.2},
    {-0.2929476584022044, 7.781438628711356, 0.2},
    {-0.5796694214876024, 7.7001652892562, 0.2},
    {-0.8846097337006438, 7.630254055708601, 0.2},
    {-1.2077685950413222, 7.5717049280685655, 0.2},
    {-1.5491460055096438, 7.524517906336087, 0.2},
    {-1.9087419651056015, 7.488692990511172, 0.2},
    {-2.2865564738292, 7.464230180593818, 0.2},
    {-2.682589531680442, 7.451129476584023, 0.2},
    {-3.0968411386593195, 7.449390878481788, 0.2},
    {-3.5293112947658423, 7.459014386287115, 0.2},
    {-3.98, 7.48, 0.2}};

    int size = sizeof(pose)/sizeof(pose[0]) -1;
    for(int i=0;i<size;i++)
    {
        geometry_msgs::PoseStamped this_pose_stamped;
        this_pose_stamped.pose.position.x = pose[i][0];
        this_pose_stamped.pose.position.y = pose[i][1];
        this_pose_stamped.pose.position.z = pose[i][2];

        //geometry_msgs::Quaternion goal_quat = tf::createQuaternionMsgFromYaw(th);
        this_pose_stamped.pose.orientation.x = 0;
        this_pose_stamped.pose.orientation.y = 0;
        this_pose_stamped.pose.orientation.z = 0;
        this_pose_stamped.pose.orientation.w = 0;

        this_pose_stamped.header.stamp=current_time;
        this_pose_stamped.header.frame_id="camera_init";
        path.poses.push_back(this_pose_stamped);
    }

    ros::Rate loop_rate(1);
    while (ros::ok())
    {

        current_time = ros::Time::now();
        //compute odometry in a typical way given the velocities of the robot

        

        path_pub.publish(path);
        ros::spinOnce();               // check for incoming messages

        last_time = current_time;
        loop_rate.sleep();
    }

    return 0;
}
