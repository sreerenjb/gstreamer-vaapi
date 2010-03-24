/*
 *  gstvaapiimageformat.h - VA image format abstraction
 *
 *  gstreamer-vaapi (C) 2010 Splitted-Desktop Systems
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef GST_VAAPI_IMAGE_FORMAT_H
#define GST_VAAPI_IMAGE_FORMAT_H

#include <va/va.h>
#include <glib/gtypes.h>

G_BEGIN_DECLS

typedef enum _GstVaapiImageFormat               GstVaapiImageFormat;

/**
 * GstVaapiImageFormat:
 * @GST_VAAPI_IMAGE_NV12:
 *   planar YUV 4:2:0, 12-bit, 1 plane for Y and 1 plane for UV
 * @GST_VAAPI_IMAGE_YV12:
 *   planar YUV 4:2:0, 12-bit, 3 planes for Y V U
 * @GST_VAAPI_IMAGE_I420:
 *   planar YUV 4:2:0, 12-bit, 3 planes for Y U V
 * @GST_VAAPI_IMAGE_AYUV:
 *   packed YUV 4:4:4, 32-bit, A Y U V, native endian byte-order
 * @GST_VAAPI_IMAGE_ARGB:
 *   packed RGB 8:8:8, 32-bit, A R G B
 * @GST_VAAPI_IMAGE_RGBA:
 *   packed RGB 8:8:8, 32-bit, R G B A
 * @GST_VAAPI_IMAGE_ABGR:
 *   packed RGB 8:8:8, 32-bit, A B G R
 * @GST_VAAPI_IMAGE_BGRA:
 *   packed RGB 8:8:8, 32-bit, B G R A
 *
 * The set of all image formats for #GstVaapiImage.
 */
enum _GstVaapiImageFormat {
    GST_VAAPI_IMAGE_NV12 = VA_FOURCC('N','V','1','2'),
    GST_VAAPI_IMAGE_YV12 = VA_FOURCC('Y','V','1','2'),
    GST_VAAPI_IMAGE_I420 = VA_FOURCC('I','4','2','0'),
    GST_VAAPI_IMAGE_AYUV = VA_FOURCC('A','Y','U','V'),
    GST_VAAPI_IMAGE_ARGB = VA_FOURCC('A','R','G','B'),
    GST_VAAPI_IMAGE_RGBA = VA_FOURCC('R','G','B','A'),
    GST_VAAPI_IMAGE_ABGR = VA_FOURCC('A','B','G','R'),
    GST_VAAPI_IMAGE_BGRA = VA_FOURCC('B','G','R','A'),
};

gboolean
gst_vaapi_image_format_is_rgb(GstVaapiImageFormat format);

gboolean
gst_vaapi_image_format_is_yuv(GstVaapiImageFormat format);

GstVaapiImageFormat
gst_vaapi_image_format(const VAImageFormat *va_format);

GstVaapiImageFormat
gst_vaapi_image_format_from_caps(GstCaps *caps);

GstVaapiImageFormat
gst_vaapi_image_format_from_fourcc(guint32 fourcc);

const VAImageFormat *
gst_vaapi_image_format_get_va_format(GstVaapiImageFormat format);

GstCaps *
gst_vaapi_image_format_get_caps(GstVaapiImageFormat format);

guint
gst_vaapi_image_format_get_score(GstVaapiImageFormat format);

G_END_DECLS

#endif /* GST_GST_VAAPI_IMAGE_H */
