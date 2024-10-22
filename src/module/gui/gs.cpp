#include "gs.h"

GS::~GS()
{
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    gst_deinit(); //очистка памяти об всех объектах gstreamer
}

GstElement* GS::getPipeline()
{
    return pipeline;
}

void GS::setVideoItem(QQuickItem* _item, const gchar* _str)
{
    g_assert(_item);
    g_object_set(sink, _str, _item, nullptr);
}

void GS::play()
{

}

//--------------------------------------------------

SetPlaying::SetPlaying (GstElement * pipeline)
{
    this->pipeline_ = pipeline ? static_cast<GstElement *> (gst_object_ref (pipeline)) : NULL;
    if (pipeline == nullptr) qDebug() << "EEEEEEEERRRRROOOORRRr";
}

SetPlaying::~SetPlaying ()
{
    if (this->pipeline_)
        gst_object_unref (this->pipeline_);
}

void SetPlaying::run ()
{
    if (this->pipeline_){
        gst_element_set_state (this->pipeline_, GST_STATE_PLAYING);
    }
}
