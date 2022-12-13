% a = arduino;
close all;
clear all;
clc
%Color = 1;
clear('cam');
cam=webcam('HD Web Camera');

% Connect to Arduino
arduinoSerialConnection = serialport("COM3",9600);
%configureTerminator(arduino_serial,"CR");

%Red:
% Define thresholds for channel 1 based on histogram settings
Redchannel1Min = 166.000;
Redchannel1Max = 240.000;

% Define thresholds for channel 2 based on histogram settings
Redchannel2Min = 50.000;
Redchannel2Max = 95.000;

% Define thresholds for channel 3 based on histogram settings
Redchannel3Min = 45.000;
Redchannel3Max = 101.000;

%Yellow:
% Define thresholds for channel 1 based on histogram settings
Yellowchannel1Min = 184.000;
Yellowchannel1Max = 255.000;

% Define thresholds for channel 2 based on histogram settings
Yellowchannel2Min = 180.000;
Yellowchannel2Max = 255.000;

% Define thresholds for channel 3 based on histogram settings
Yellowchannel3Min = 39.000;
Yellowchannel3Max = 123.000;


%Blue:
% Define thresholds for channel 1 based on histogram settings
Bluechannel1Min = 40.000;
Bluechannel1Max = 61.000;

% Define thresholds for channel 2 based on histogram settings
Bluechannel2Min = 105.000;
Bluechannel2Max = 129.000;

% Define thresholds for channel 3 based on histogram settings
Bluechannel3Min = 209.000;
Bluechannel3Max = 255.000;

while( true)
response = 0;
RGB = snapshot(cam);
figure(1)
imshow(RGB) %original
%%%%%%%%%%%%%% FROM colorThresholder %%%%%%%%%%%%%%%%%%
% I used the Matlab app colorThresholder to find the points for my mask, which is red
% Convert RGB image to chosen color space
I = RGB;
sliderBWRed = ( (I(:,:,1) >= Redchannel1Min) & (I(:,:,1) <= Redchannel1Max) ) & ...
(I(:,:,2) >= Redchannel2Min ) & (I(:,:,2) <= Redchannel2Max) & ...
(I(:,:,3) >= Redchannel3Min ) & (I(:,:,3) <= Redchannel3Max);
BWRed = sliderBWRed;

sliderBWYellow = ( (I(:,:,1) >= Yellowchannel1Min) & (I(:,:,1) <= Yellowchannel1Max) ) & ...
(I(:,:,2) >= Yellowchannel2Min ) & (I(:,:,2) <= Yellowchannel2Max) & ...
(I(:,:,3) >= Yellowchannel3Min ) & (I(:,:,3) <= Yellowchannel3Max);
BWYellow = sliderBWYellow;

sliderBWBlue = ( (I(:,:,1) >= Bluechannel1Min) & (I(:,:,1) <= Bluechannel1Max) ) & ...
(I(:,:,2) >= Bluechannel2Min ) & (I(:,:,2) <= Bluechannel2Max) & ...
(I(:,:,3) >= Bluechannel3Min ) & (I(:,:,3) <= Bluechannel3Max);
BWBlue = sliderBWBlue;

% Initialize output masked image based on input image.
RedmaskedRGBImage = RGB;
YellowmaskedRGBImage = RGB;
BluemaskedRGBImage = RGB;
% Set background pixels where BW is false to zero.
RedmaskedRGBImage(repmat(~BWRed,[1 1 3])) = 0;
YellowmaskedRGBImage(repmat(~BWYellow,[1 1 3])) = 0;
BluemaskedRGBImage(repmat(~BWBlue,[1 1 3])) = 0;

%%%%%%%%%%%%% END FROM colorThresholder %%%%%%%%%%%%%%%%
rpcount = 0;
i = 540;
j = 960;
        if( RedmaskedRGBImage(i:i+20,j:j+20,1) >= Redchannel1Min & RedmaskedRGBImage(i:i+20,j:j+20,1) <= Redchannel1Max & ...
(RedmaskedRGBImage(i:i+20,j:j+20,2) >= Redchannel2Min ) & (RedmaskedRGBImage(i:i+20,j:j+20,2) <= Redchannel2Max) & ...
(RedmaskedRGBImage(i:i+20,j:j+20,3) >= Redchannel3Min ) & (RedmaskedRGBImage(i:i+20,j:j+20,3) <= Redchannel3Max))
            response = 1;
            write(arduinoSerialConnection,response,"int8")
            pause(35);
        end
        if( YellowmaskedRGBImage(i:i+20,j:j+20,1) >= Yellowchannel1Min & YellowmaskedRGBImage(i:i+20,j:j+20,1) <= Yellowchannel1Max & ...
(YellowmaskedRGBImage(i:i+20,j:j+20,2) >= Yellowchannel2Min ) & (YellowmaskedRGBImage(i:i+20,j:j+20,2) <= Yellowchannel2Max) & ...
(YellowmaskedRGBImage(i:i+20,j:j+20,3) >= Yellowchannel3Min ) & (YellowmaskedRGBImage(i:i+20,j:j+20,3) <= Yellowchannel3Max))
            response = 2;
            write(arduinoSerialConnection,response,"int8")
            pause(35);
        end
        if( BluemaskedRGBImage(i:i+20,j:j+20,1) >= Bluechannel1Min & BluemaskedRGBImage(i:i+20,j:j+20,1) <= Bluechannel1Max & ...
(BluemaskedRGBImage(i:i+20,j:j+20,2) >= Bluechannel2Min ) & (BluemaskedRGBImage(i:i+20,j:j+20,2) <= Bluechannel2Max) & ...
(BluemaskedRGBImage(i:i+20,j:j+20,3) >= Bluechannel3Min ) & (BluemaskedRGBImage(i:i+20,j:j+20,3) <= Bluechannel3Max))
            response = 3;
            write(arduinoSerialConnection,response,"int8")
            pause(35);
        end

end