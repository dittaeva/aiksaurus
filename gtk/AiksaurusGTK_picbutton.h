/*
 * AiksaurusGTK - A GTK interface to the AikSaurus library
 * Copyright (C) 2001 by Jared Davis
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef INCLUDED_GPL_JARED_AIKSAURUSGTK_PICBUTTON_H
#define INCLUDED_GPL_JARED_AIKSAURUSGTK_PICBUTTON_H

#include <glib.h>
#include <gtk/gtk.h>

class AiksaurusGTK_picbutton
{
	private:

		GtkWidget* d_window_ptr;
		GtkWidget* d_button_ptr;

		GtkWidget* d_pixmap_ptr;
		GtkStyle* d_style_ptr;
	
		GdkPixmap* d_normalpixmap_ptr;
		GdkBitmap* d_normalmask_ptr;
		
		GdkPixmap* d_hoverpixmap_ptr;
		GdkBitmap* d_hovermask_ptr;
		
		GdkPixmap* d_disabledpixmap_ptr;
		GdkBitmap* d_disabledmask_ptr;
		
		bool d_enabled;

		static void cbEntered(GtkWidget* w, gpointer data);
		static void cbLeft(GtkWidget* w, gpointer data);
	
		void hover();
		void unhover();
		
	public:

		AiksaurusGTK_picbutton(GtkWidget *window, const char** normal);
		
		void setHoverPicture(const char** hover);
		void setDisabledPicture(const char** disabled);
		
		void disable();
		void enable();

		GtkWidget* getButton();
};

#endif // INCLUDED_GPL_JARED_AIKSAURUSGTK_PICBUTTON_H