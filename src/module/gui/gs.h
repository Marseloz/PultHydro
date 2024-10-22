#ifndef GS_H
#define GS_H

#include <QQuickItem>
#include <QObject>
#include <QRunnable>
#include <gst/gst.h>

class GS {
public:
    GS(){
        _init();
    }
    GS(QQuickItem** a){
        _init();
        g_assert (a);
        g_object_set(sink, "widget", a, nullptr);
    }
    ~GS();
    GstElement* getPipeline();
    void play();
    void setVideoItem(QQuickItem* _item, const gchar* _str);
private:
    GstElement *pipeline;
    GstElement *parser;
    GstElement *queue;
    GstElement *deparser;
    GstElement *coder;
    GstElement *camera;
    GstElement *src;
    GstElement *buffer;
    GstElement *capsfilter;
    GstElement *filter;
    GstElement *demuxer;
    GstElement *glsinkbin;
    GstElement *decode;
    GstElement *sink;
    std::string host = "127.0.0.1";
    int port = 5600;
    GError *error = nullptr;

    void _init(){
        gst_init (nullptr, nullptr);
        pipeline = gst_pipeline_new ("tesst");
        src = gst_element_factory_make ("udpsrc", "src");
        //g_object_set(src, "uri", "udp://127.0.0.1:5600", nullptr);
        g_object_set(src, "address", host.c_str(), "port", port, nullptr);
        //camera = gst_element_factory_make ("mfvideosrc", NULL);
        //capsfilter = gst_element_factory_make ("capsfilter", NULL);
        GstCaps* convertCaps = gst_caps_from_string("application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=H264");
        g_object_set(src, "caps", convertCaps, nullptr);
        gst_caps_unref(convertCaps);

        filter = gst_element_factory_make ("capsfilter", NULL);
        convertCaps = gst_caps_from_string("video/x-h264,stream-format=avc");
        g_object_set(filter, "caps", convertCaps, nullptr);
        gst_caps_unref(convertCaps);

        buffer = gst_element_factory_make ("rtpjitterbuffer", NULL);
        //g_object_set(buffer, "rfc7273-use-system-clock", 1, nullptr);
        demuxer = gst_element_factory_make ("rtpgstdepay", NULL);

        //deparser = gst_element_factory_make ("rtph264pay", NULL);
        parser = gst_element_factory_make ("parsebin", NULL);
        decode = gst_element_factory_make ("decodebin3", NULL);
        coder = gst_element_factory_make ("h264parse", NULL);
        queue = gst_element_factory_make ("glcolorconvert", NULL);
        glsinkbin = gst_element_factory_make ("glupload", NULL);
        sink = gst_element_factory_make ("qml6glsink", "sink");
        //g_object_set (glsinkbin, "sink", sink, NULL);


        // GstCaps *caps = gst_caps_new_simple("video/x-raw", "width", G_TYPE_INT, 192, "height", G_TYPE_INT, 108, nullptr);
        // g_object_set(capsfilter, "caps", caps, nullptr); //применяем настройки к объекту
        // gst_caps_unref(caps);

        g_assert (src && filter && buffer && demuxer && decode && glsinkbin);

        gst_bin_add_many (GST_BIN (pipeline), src, parser, decode, glsinkbin, queue, sink, NULL, nullptr);
                        gst_element_link_many (src, parser, decode, glsinkbin, queue, sink, NULL, nullptr);
    }
    // void _init(){
    //     gst_init (nullptr, nullptr);
    //     pipeline = gst_pipeline_new (NULL);
    //     src = gst_element_factory_make ("videotestsrc", NULL);
    //     capsfilter = gst_element_factory_make ("capsfilter", NULL);
    //     glsinkbin = gst_element_factory_make ("glupload", NULL);
    //     sink = gst_element_factory_make ("qml6glsink", NULL);

    //     g_object_set(src, "pattern", 0, nullptr);

    //     GstCaps *caps = gst_caps_new_simple("video/x-raw", "width", G_TYPE_INT, 1920, "height", G_TYPE_INT, 1080, nullptr);
    //     g_object_set(capsfilter, "caps", caps, nullptr); //применяем настройки к объекту
    //     gst_caps_unref(caps);

    //     g_assert (src && capsfilter && glsinkbin && sink);

    //     gst_bin_add_many (GST_BIN (pipeline), src, capsfilter, glsinkbin, sink, nullptr);
    //     gst_element_link_many (src, capsfilter, glsinkbin, sink, nullptr);
    // }
};


class SetPlaying : public QRunnable {
public:
  SetPlaying(GstElement *);
  ~SetPlaying();
  void run ();
private:
  GstElement * pipeline_;
};

#endif // GS_H
