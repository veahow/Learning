"""HelloWorld URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.8/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import include, url
from django.contrib import admin
from Hello import views as Hello_views
from Calc import views as Calc_views

urlpatterns = [
    url(r'^admin/', include(admin.site.urls)),
    # url(r'$', Hello_views.index),
    # url(r'^add/$', Calc_views.add, name='add'),
    # url(r'^add/(\d+)/(\d+)/$', Calc_views.add2, name='add2'),
    url(r'^$', Hello_views.home, name='home'),
]
