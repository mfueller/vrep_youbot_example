# YouBot Example

## Set up V-REP
1. Download and extract v-rep, e.g. into /opt/v-rep from www.v-rep.eu

2. In the v-rep directory (/opt/v-rep) check the following lines in the file *remoteApiConnections.txt*

  portIndex1_port                 = 19997

  portIndex1_debug                = true

  portIndex1_syncSimTrigger       = false

## Run the simulation
1. Start v-rep by `./v-rep.sh`

2. Load /scence/youbot_arm

3. Start the simulation

4. Run your code (see next section)

## Running your code using the remote API
### C++
First compile your code:
> $ cmake /path_to_CMakeLists.txt/ -DVREP_DIR:PATH=/path_to_v-rep/

In our case, for example:
```
$ cd vrep_youbot_example
$ mkdir build
$ cmake .. -DVREP_DIR:PATH=/opt/v-rep
$ make
```

To run the example run `$ ./example`

### Python

1. Make sure the remote API libraries are compiled:
  ```
  $ cd /opt/v-rep/programming/remoteApiBindings/lib
  $ make
  $ sudo cp /opt/v-rep/programming/remoteApiBindings/lib/lib/64Bit/remoteApi.so /opt/v-rep/programming/remoteApiBindings/python/python
  ```

2. You need to add the python modules to you python path, e.g.

  ```
  $ export PYTHONPATH=$PYTHONPATH:/opt/v-rep/programming/remoteApiBindings/python/python
  ```

  and the shared object library to you LD_LIBRARY_PATH, e.g.

  ```
  $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/v-rep/programming/remoteApiBindings/lib/lib/64Bit
  ```

  Note: if python does not find the module or the library, you can simply copy the files into your working directory.

To run your code simply use `python youbot_example.py`

### KDL chain

Example code for creating the propper KDL chain
```cpp
KDL::Chain chain;
double offset[5] = {d2r(-169),d2r(-65),d2r(147),d2r(-102.5),d2r(-167.5)};
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None), KDL::Frame::DH(0.0, M_PI, 0.147, 0)));

chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame::DH(0.033,  + M_PI_2,  0.0, offset[0] + M_PI       )));
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame::DH(0.155,  0,    0.000,  offset[1] - M_PI_2)));
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame::DH(0.135,  0,    0.000,  offset[2]    )));
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame::DH(0.0,  M_PI_2,       0.0,  offset[3] - M_PI_2   )));
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::RotZ), KDL::Frame::DH(0.0, 0,  0.0,  offset[4])));

chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None), KDL::Frame::DH(0.00, 0, -0.208, 0)));
chain.addSegment(KDL::Segment(KDL::Joint(KDL::Joint::None), KDL::Frame::DH(0.00, M_PI, 0, 0)));
```
