#include <DarkHelp.hpp>
#include <filesystem>
#include <iostream>

int main()
{
    DarkHelp::Config cfg("/home/strange/ambulance_project/nn/ambulence_data.cfg", "/home/strange/ambulance_project/nn/ambulence_data_best.weights", "/home/strange/ambulance_project/nn/ambulence_data.names");
    cfg.enable_tiles                    = false;
    cfg.combine_tile_predictions        = false;
    cfg.annotation_auto_hide_labels        = false;
    cfg.annotation_include_duration    = false;
    cfg.annotation_include_timestamp    = false;
    cfg.non_maximal_suppression_threshold = 0.05;
    cfg.annotation_suppress_all_labels = false;
    DarkHelp::NN nn(cfg);

    nn.config.annotation_line_thickness    = 1;
    nn.config.combine_tile_predictions    = false;
    nn.config.threshold                     = 0.3;
    
    std::filesystem::path directoryPath = "/home/strange/ambulance_project/set_01/";

    // Iterate over files in the directory
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath))
    {
        if (entry.is_regular_file())
        {
            std::string filePath = entry.path().string();

            // Apply the neural network to the current image
            const auto results = nn.predict(filePath);

            // Print the neural network results on the console
            std::cout << results << std::endl;

            // Display both the original image and the annotated image using OpenCV HighGUI
            cv::Mat img1 = nn.original_image;
            cv::Mat img2 = nn.annotate();

            const cv::Size size(480, 480);
            cv::imshow("img1", DarkHelp::resize_keeping_aspect_ratio(img1, size));
            cv::imshow("img2", DarkHelp::resize_keeping_aspect_ratio(img2, size));
            cv::waitKey();
        }
    }

    return 0;
}

